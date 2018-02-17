#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.000000001;

int n, m, u, v, num;
vector<int> adj[N];
bool vis[N];

void DFS(int p){
	vis[p] = 1;
	for(int ch : adj[p])
		if(!vis[ch])	DFS(ch);
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!vis[i])	DFS(i), ++num;
	}
	printf("%d\n", num);
	return 0;
}
