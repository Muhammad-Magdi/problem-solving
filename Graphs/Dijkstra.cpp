#include <bits/stdc++.h>

using namespace std;

const int N = (1<<22), M = (1<<18), OO = 0x3f3f3f3f;

vector<pair<int, int> > adj[N];
int n, m, u, v, c, s;
int dis[N];

void Dijkstra(int src){
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src});
	dis[src] = 0;
	while(!pq.empty()){
		int p = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if(d > dis[p])	continue;
		for(pair<int, int> ch : adj[p]){
			if(dis[ch.second] > d+ch.first){
				dis[ch.second] = d+ch.first;
				pq.push(make_pair(-dis[ch.second], ch.second));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	memset(dis, OO, sizeof dis);
	scanf("%d", &s);
	Dijkstra(s);
	for(int i = 1 ; i <= n ; ++i){
		printf("Shortest path from %d to %d is %d\n", s, i, dis[i]);
	}
  return 0;
}
