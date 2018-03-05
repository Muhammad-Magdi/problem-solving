#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+9, M = 1e3+9, OO = 1000000007;
const double EPS = 0.0000001;

char grid[10][10];
int ops ;
int rVis[10][10], cVis[10][10], bVis[10][10];

pair<int, int> nextCell(pair<int, int> cell){
  if(cell.second == 8)  return {cell.first+1, 0};
  return {cell.first, cell.second+1};
}

bool valid(int r, int c){
  for(int i = 0 ; i < 9 ; ++i){
    if(i!=c && grid[r][c] == grid[r][i])  return 0;
    if(i!=r && grid[r][c] == grid[i][c])  return 0;
  }
  int rBox = (r/3)*3, cBox = (c/3)*3;
  for(int i = rBox ; i < rBox + 3 ; ++i){
    for(int j = cBox ; j < cBox + 3 ; ++j){
      if((i!=r || j!=c) && grid[r][c] == grid[i][j])  return 0;
    }
  }
  return 1;
}

bool solve(pair<int, int> cell){
  ++ops;
  int r = cell.first, c = cell.second;
  if(r == 8 && c == 8 && grid[r][c] != 'x') return 1;
  if(grid[r][c] != 'x') return solve(nextCell(cell));
  for(char i = '1' ; i<='9' ; ++i){
    grid[r][c] = i;     //Do
    if(r == 8 && c == 8 && valid(r, c)) return 1;
    else if(valid(r, c) && solve(nextCell(cell)))  return 1;   //recurse
    grid[r][c] = 'x';   //undo
  }
  return 0;
}

void printGrid(){
  printf("-------------------\n");
  for(int i = 0 ; i < 9 ; ++i){
    for(int j = 0 ; j < 9 ; ++j){
      if(!j)  printf("|");
      printf("%c%c", grid[i][j], ((j+1)%3==0? '|' : ' '));
    }
    puts("");
    if((i+1)%3==0) printf("-------------------\n");
  }
}

int main(){
  freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  for(int i = 0 ; i < 9 ; ++i)
    scanf("%s", grid[i]);
  if(solve({0, 0})) printGrid();
  else puts("INVALID");
  printf("%d\n", ops);
  return 0;
}
