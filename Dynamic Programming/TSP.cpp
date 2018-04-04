#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
const int N = 18 , M = (1<<14), OO = 0x3f3f3f3f;

int src;
int n, m;
int adj[N][N];
int mem[N][1<<N];

int solve(int i = src, int msk = (1<<src)){
	if(msk == (1<<n)-1)	return adj[i][src];
	int & ret = mem[i][msk];
	if(~ret)	return ret;
	ret = OO;
	for(int ch = 0 ; ch < n ; ++ch){
		if(i == ch || msk&(1<<ch))	continue;
		ret = min(ret, solve(ch, msk|(1<<ch)) + adj[i][ch]);
	}
	return ret;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &src);
	memset(mem, -1, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < n ; ++j)
			scanf("%d", adj[i]+j);
	printf("%d\n", solve());
	return 0;
}
