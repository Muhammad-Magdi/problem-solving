#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.000000001;

int n, m, u, v, x, maxi, first, IsDAG = 1;
vector<int > adj[N];
int vis[N];

void DFS(int p){											//p = parent
	vis[p] = 2;													//In Stack
	for(int ch : adj[p]){								//ch = child
		if(vis[ch] == 2)	IsDAG = 0;			//Here's a cycle
		if(!vis[ch])	DFS(ch);						//Recurse
	}
	vis[p] = 1;													//Visited
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i = 1 ; i <= n ; ++i){			//-try to-Traverse starting from each non-visited node
		if(!vis[i])	DFS(i);
	}
	puts(IsDAG? "DAG" : "NOT a DAG");
	return 0;
}
