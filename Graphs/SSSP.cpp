#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n, m, a, b, x;
vector<int> adj[N];
int dis[N];

void BFS(int src){
	queue<int> q;
	q.push(src);
	dis[src] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int ch : adj[p])if(dis[ch]==OO){
			dis[ch] = dis[p]+1;
			q.push(ch);
		}
	}
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> x;
	memset(dis, OO, sizeof dis);
	BFS(x);
	for(int i = 1 ; i <= n ; ++i)
		printf("The Shortest Path between %d and %d is %d\n", x, i, dis[i]);
	return 0;
}
