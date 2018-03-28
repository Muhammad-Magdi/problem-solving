/*
  Different Solutions for LIS Problem
  Muhammad Magdi
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1000, M = 2e6, OO = 1000000007, EPS = 0.00000001;

int n , A[N+9], mem[N+9][N+9];

/********************* Recursive DP Solution *********************/

int LIS(int i = 0, int prev = n){     //Memory -> O(n^2), Time -> O(n^2)
  if(i == n)  return mem[i][prev] = 0;
  int &ret = mem[i][prev];
  if(~ret)  return ret;
  return ret = max(LIS(i+1, prev), (A[i]>A[prev]? LIS(i+1, i)+1 : 0));
}

void buildLIS(int i = 0, int prev = n){
  if(i==n)  return;
  if(~mem[i+1][prev] && mem[i][prev] == mem[i+1][prev])          //we left it
    buildLIS(i+1, prev);
  else if(~mem[i+1][i] && mem[i][prev] == mem[i+1][i]+1){     //we took it
    printf("%d ", A[i]);
    buildLIS(i+1, i);
  }
}

/********************* Iterative DP Solution *********************/

int dp[N+9][N+9];
int iterativeLIS(){    //Memory -> O(n^2), Time -> O(n^2)
  for(int i = 0 ; i <= n ; ++i)
    dp[n][i] = 0;
  for(int i = n-1 ; ~i ; --i)
    for(int prev = n ; ~prev ; --prev)
      dp[i][prev] = max(dp[i+1][prev], ((prev == n || A[i]>A[prev])? dp[i+1][i]+1 : 0));
  return dp[0][n];
}

int rdp[2][N+9];
int rollingLIS(){    //Memory -> O(n), Time -> O(n^2)
  int r = 0;
  for(int i = 0 ; i <= n ; ++i)     //Base Case
    rdp[r][i] = rdp[!r][i] = 0;
  for(int i = n-1 ; ~i ; --i){      //Bottom-Up Approach
    r = !r;                         //switch to the other row
    for(int prev = n ; ~prev ; --prev)
      rdp[r][prev] = max(rdp[!r][prev], ((prev == n || A[i]>A[prev])? rdp[r][i]+1 : 0));
  }
  return rdp[r][n];
}

/********************* BinarySearch Solution *********************/

int binarySearchLIS(){    //Memory -> O(n), Time -> O(nLogn)
  vector<int> ret;
  for(int i=0; i<n; i++){
    auto it = lower_bound(ret.begin(), ret.end(), A[i]);
    if(it == ret.end()) ret.push_back(A[i]);
    else *it = A[i];
  }
  return (int)ret.size();
}

void binarySearchLISWithBuilding(){    //Memory -> O(n), Time -> O(nLogn)
  int LIS = 0, ret[N+9] , last = -1;
  set<int> retset[N+9];
  for(int i=0; i<n; i++){
    auto it = lower_bound(ret, ret+LIS, A[i]);
    if(it == ret+LIS)   ret[LIS++] = A[i];
    else                ret[LIS-1] = A[i];
    retset[LIS].insert(A[i]);
  }
  /*Printing*/
  printf("Binary Search says LIS = %d\n", LIS);
  printf("And a valid sub-sequence is : ");
  for(int i = 1 ; i<=LIS ; ++i){
    auto it = retset[i].upper_bound(last);
    printf("%d ", (last = *it));
  }
  puts("");
}

/********************* Segment Tree Solution *********************/

#define lft(x) (x<<1)
#define rit(x) (x<<1|1)
#define med(l, r) ((l+r)>>1)

int st[N<<2];

void update(int p, int l, int r, int idx, int val){
	if(l>r || l>idx || r<idx)	return;		//invalid segment
	if(l==r)	st[p] = val;
	else{
		update(lft(p), l, med(l, r), idx, val);
		update(rit(p), med(l, r)+1, r, idx, val);
		st[p] = max(st[lft(p)], st[rit(p)]);
	}
}

int getMax(int p, int l, int r, int i, int j){
	if(l>r || l>j || r<i)	return 0;
	if(l>=i && r<=j)	return st[p];
	int q1 = getMax(lft(p), l, med(l, r), i, j);
	int q2 = getMax(rit(p), med(l, r)+1, r, i, j);
	return max(q1, q2);
}

bool cmp(pair<int, int> &a, pair<int, int> & b){
	//ascending values then descending indices to get LIS
	if(a.first == b.first)	return a.second>b.second;
	return a.first < b.first;
}

void segmentTreeLIS(){		//Memory -> O(n), Time -> O(nLogn)
	pair<int, int> arr[n+5];		//pair of value and index
	for(int i = 0 ; i < n ; ++i)
		arr[i] = {A[i], i};
	sort(arr, arr+n, cmp);
	for(int i = 0 ; i < n ; ++i){
		int beforeMe = getMax(1, 0, n-1, 0, arr[i].second);
		update(1, 0, n-1, arr[i].second, beforeMe+1);
	}
	printf("Segment Tree says that LIS = %d\n", st[1]);
}

/********************* main function *********************/

int main(){
	// freopen("i.in", "r", stdin);
	// freopen("o.out", "w", stdout);
  memset(mem, -1, sizeof mem);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  printf("Recursive Solution says LIS = %d\n", LIS());
  printf("And a valid sub-sequence is : ");
  buildLIS();
  puts("");
  printf("Iterative Solution says LIS = %d\n", iterativeLIS());
  printf("With Rolling the answer is %d\n", LIS());
  binarySearchLISWithBuilding();
  segmentTreeLIS();
  return 0;
}

/* input samples
5
1 4 2 4 3

6
2 4 3 4 1 6
*/
