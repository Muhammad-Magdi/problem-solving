#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n, m, rx, ry, cx, cy;
string grid[N];
int dis[N][N];
int dx[] = {1, -1, 0, 0};			//Four Dimensions
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y){				//All the conditions required to visit this node
	return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#' && dis[x][y]==OO);
}

void BFS(int ratx, int raty){
	queue<pair<int, int> > q;
	q.push({ratx, raty});
	dis[ratx][raty] = 0;
	while(!q.empty()){
		int parentx = q.front().first, parenty = q.front().second;
		q.pop();
		for(int i = 0 ; i < 4 ; ++i){
			int childx = parentx+dx[i], childy=parenty+dy[i];
			if(!valid(childx, childy))	continue;
			dis[childx][childy] = dis[parentx][parenty] + 1;
			q.push({childx, childy});
		}
	}
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	memset(dis, OO, sizeof dis);
	cin >> n >> m;
	for(int i = 0 ; i < n ; ++i)
		cin >> grid[i];
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(grid[i][j] == 'R')	rx = i, ry = j;
			else if(grid[i][j] == 'C')	cx = i, cy = j;
		}
	}
	BFS(rx, ry);
	if(dis[cx][cy]==OO)
		puts("The Cheese isn't reachable");
	else
		printf("The shortest Path from Rat to Cheese is %d steps.\n", dis[cx][cy]);
	return 0;
}
