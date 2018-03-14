#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = (1<<16), OO = 0x3f3f3f3f;

int n, m, A[N][N];
int mem[N][N];										

int maximumPathSum(int i=0, int j=0){
	if(i==n-1 && j==m-1)	return 0;
	int & ret = mem[i][j];
	if(ret != OO)	return ret;
	return ret=max(i+1<n? maximumPathSum(i+1, j) : -OO, j+1<m? maximumPathSum(i, j+1) : -OO) + A[i][j];
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &m);
	memset(mem, OO, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			scanf("%d", A[i]+j);
	printf("%d\n", maximumPathSum());
	return 0;
}


















