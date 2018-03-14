#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = (1<<16), OO = 0x3f3f3f3f;

int n, W[N], C[N], k;
int mem[N][N];										//O(n*k)

int KS(int i = 0, int rem = k){		//O(n*k)
	if(i == n)	return 0;
	int & ret = mem[i][rem];
	if(~ret)	return ret;
	return ret = max(rem>=W[i]? KS(i+1, rem-W[i])+C[i] : -OO, KS(i+1, rem));
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &k);
	memset(mem, -1, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d", W+i, C+i);
	printf("%d\n", KS());
	return 0;
}


















