#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5 , M = 2e3 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.0000001, PI = 2*acos(0.0);

vector<int> adj1[N];								//adjacency list
vector<pair<int, int> > adj2[N];		//adjacency list for a weighted graph
int adj3[M][M];											//adjacency matrix

int n, m, u, v, c;

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){			//number of edges
		cin >> u >> v >> c;							// from, to and weight
		adj1[u].push_back(v);
		adj1[v].push_back(u);						//for undirected graphs
		
		/*	in a weighted graph
		adj2[u].push_back({c, v});
		adj2[v].push_back({c, u});
		*/
		
		/*	or using adjacency matrix
		adj3[u][v] = c;
		adj3[v][u] = c;
		*/
	}
  return 0;
}













