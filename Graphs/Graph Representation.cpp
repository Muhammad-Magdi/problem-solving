#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = 2e3 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.0000001, PI = 2*acos(0.0);

vector<pair<int, int> > edgelist;			//unweighted edge list
vector<pair<int, pair<int, int> > wEdgeList;		//weighted edge list

bool adjMat[N][N];					//unweighted adjacency matrix
int wAdjMat[N][N];					//weighted adjacency matrix

vector<int> adjList[N];					//unweighted adjacency list
vector<pair<int, int> > wAdjList[N];			//weighted adjacency list

int n, m, u, v, c;

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
 	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){			//number of edges
		cin >> u >> v;				// from, to
		adj1[u].push_back(v);
		adj1[v].push_back(u);			//for undirected graphs

		/*	in a weighted graph
		cin >> u >> v >> c;
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













