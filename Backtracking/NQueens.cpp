#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 +5 , M = 1e4 +5, OO = 1000000007;

int n;
bool r[N], md[2*N+5], sd[5*N+5];
bool board[N][N];

void printSolution(){
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0; j < n ; ++j)
      printf("%c", board[i][j]? 'Q' : '.');
    puts("");
  }
}

bool valid(int x, int y){
  return (!r[x] && !md[x-y+2*N] && !sd[x+y]);
}

bool solveNQ(int col = 0){
  if(col>=n)  return 1;
  for(int row = 0 ; row < n ; ++row){
    if(valid(row, col)){
      r[row] = 1;
      md[row-col+2*N] = 1;
      sd[row+col] = 1;
      board[row][col] = 1;
      if(solveNQ(col+1))  return 1;
      r[row] = 0;
      md[row-col+2*N] = 0;
      sd[row+col] = 0;
      board[row][col] = 0;
    }
  }
  return 0;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  scanf("%d", &n);
  if(solveNQ()) printSolution();
  else  printf("No Solution\n");
  return 0;
}









/*
*/
