#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.000000001;

int n, m, u, v;
vector<int> adj[N];
bool vis[N];

/*
void DFS(int p){			//iterative DFS
	stack<int> st;
	st.push(p);
	vis[p] = 1;
	while(!st.empty()){
		int p = st.top();
		st.pop();
		for(int ch : adj[p]){
			if(!vis[ch])	st.push(ch);
			vis[ch] = 1;
		}
	}
}
*/

void DFS(int p){						//topological ordering
	vis[p] = 1;
	for(int ch : adj[p])			//Finish all the dependencies
		if(!vis[ch])	DFS(ch);	//..,
	printf("%d ", p);					//then print me
}


int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> u >> v;
		adj[v].push_back(u);					//Reverse edges
	}
	for(int i = 1 ; i <= n ; ++i){	//-try to-Traverse starting from each non-visited node
		if(!vis[i])	DFS(i);
	}
	return 0;
}
