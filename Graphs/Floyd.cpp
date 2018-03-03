#include <bits/stdc++.h>

using namespace std;

const int N = (1<<9), M = (1<<18), OO = 0x3f3f3f3f;

int adj[N][N];
int n, m, u, v, c;

int main() {
	scanf("%d %d", &n, &m);
	memset(adj, OO, sizeof adj);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d", &u, &v, &c);
		adj[u][v] = c;
	}
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			printf("%10d%c", adj[i][j], " \n"[j==n]);
		}
	}
  return 0;
}
