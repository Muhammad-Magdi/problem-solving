#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 +5 , M = 1e4 +5, OO = 1000000007;

int grid[N][N], n, m;

bool valid(int r, int c){
  return (r<n && r>=0 && c<m && c>=0 && grid[r][c]!=0);
}
vector<pair<int, int> > path;

void printPath(){
  for(pair<int, int> q : path)
    printf("%d %d\n", q.first, q.second);
}

bool solveRIM(int r = 0, int c = 0){
  if(r==n-1 && c==m-1)  return 1;
  if(valid(r, c+1)){
    path.push_back({r, c+1});
    if(solveRIM(r, c+1))  return 1;
    path.pop_back();
  }
  if(valid(r+1, c)){
    path.push_back({r+1, c});
    if(solveRIM(r+1, c))  return 1;
    path.pop_back();
  }
  return 0;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      scanf("%d", &grid[i][j]);
  if(solveRIM()){
    printPath();
  }else{
    printf("No Solution");
  }
  return 0;
}









/*
*/
