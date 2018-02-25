#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n, m, a, b;
vector<int> adj[N];
int col[N];

bool BFS(int src){
	queue<int> q;
	q.push(src);
	col[src] = 0;								//Give it some color
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int ch : adj[p]){
			if(col[ch] == OO){			//If my child isn't colored
				col[ch] = !col[p];		//give him NOT my color
				q.push(ch);						
			}else if(col[ch]==col[p]){		//if my child's color is the same as mine
				return 0;										//so, it can't be a bipartite -bicolorable- graph
			}
		}
	}
	return 1;													//It can be Bipartite
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	memset(col, OO, sizeof col);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(col[i]==OO){		//BFS from each non-visited node
			if(!BFS(i)){
				printf("Not BiPartite\n");
				return 0;
			}	
		}
	}
	puts("Bipartite");
	return 0;
}












