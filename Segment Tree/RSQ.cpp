#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5 , M = (N<<2), OO = 1000000007;
const double EPS = 0.00001;

#define lft(x) (x<<1)
#define rit(x) (x<<1|1)
#define med(l, r) ((l+r)>>1)

int n, q, t, a, b;
int A[N];

int tr[N<<2];

void build(int p, int l, int r){					//O(n*log(n))
	if(l==r)
		tr[p] = A[l];
	else{
		build(lft(p), l, med(l, r));
		build(rit(p), med(l, r)+1, r);
		tr[p] = tr[lft(p)] + tr[rit(p)];
	}
}

void update(int p, int l, int r, int idx, int val){			//O(log(n))
	if(l>r || l>idx || r<idx)	return;
	if(l==r)
		tr[p] = val;
	else{
		update(lft(p), l, med(l, r), idx, val);
		update(rit(p), med(l, r)+1, r, idx, val);
		tr[p] = tr[lft(p)] + tr[rit(p)];
	}
}

int sum(int p, int l, int r, int i, int j){				//O(log(n))
	if(l>r || l>j || r<i)	return 0;
	if(l>=i && r<=j)	return tr[p];
	else{
		int q1 = sum(lft(p), l, med(l, r), i, j);
		int q2 = sum(rit(p), med(l, r)+1, r, i, j);
		return q1 + q2;
	}
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  cin.sync_with_stdio(0);
	cin >> n;
	for(int i = 0 ; i < n ; ++i)
		cin >> A[i];
	cin >> q;
	build(1, 0, n-1);
	while(q--){
			cin >> t >> a >> b;
			if(t){
				printf("The sum from %d to %d is %d\n", a, b, sum(1, 0, n-1, a, b));
			}else{
				update(1, 0, n-1, a, b);
			}
	}
  return 0;
}

/*
Sample Input:
5
5 4 3 6 5
6
1 0 4
0 3 -10
1 0 4
1 0 0
0 0 2
1 0 2
*/
