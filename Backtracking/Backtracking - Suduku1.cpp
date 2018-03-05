#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+9, M = 1e3+9, OO = 1000000007;
const double EPS = 0.0000001;

char grid[10][10];
int ops ;
int rVis[10][10], cVis[10][10], bVis[10][10];

bool isVis(int r, int c, int val){
  int b = (r/3) * 3 + c / 3;
  return (rVis[r][val] || cVis[c][val] || bVis[b][val]);
}

bool isValid(int r, int c){
  int vis[12] = {};
  for(int i = 0 ; i < 9 ; ++i){   //check my row
    if(grid[r][i] != 'x' && vis[grid[r][i] - '0'])  return 0;
    else if(grid[r][i] != 'x')  vis[grid[r][i] - '0'] = 1;
  }
  memset(vis, 0, sizeof vis);
  for(int i = 0 ; i < 9 ; ++i){    //check my Column
    if(grid[i][c] != 'x' && vis[grid[i][c] - '0'])  return 0;
    else if(grid[i][c] != 'x')  vis[grid[i][c] - '0'] = 1;
  }
  memset(vis, 0, sizeof vis);
  int rBox = r/3, cBox = c/3;
  for(int i = 0 ; i < 3 ; ++i)    //check my box
    for(int j = 0 ; j < 3 ; ++j){
      int x = 3*rBox + i, y = 3*cBox + j;
      if(grid[x][y] != 'x' && vis[grid[x][y] - '0'])  return 0;
      else if(grid[x][y] != 'x')  vis[grid[x][y] - '0'] = 1;
    }
  return 1;
}

pair<int, int> nextCell(pair<int, int> &x){
  if(x.second == 8) return {x.first+1, 0};
  return {x.first, x.second+1};
}

bool isAllValid(){
  for(int i = 0 ; i < 9 ; ++i)
    if(!isValid(i, i))  return 0;
  return 1;
}

void visit(int r, int c, int val){
  int b = (r/3) * 3 + c / 3;
  rVis[r][val] = cVis[c][val] = bVis[b][val] = 1;
}

void unvisit(int r, int c, int val){
  int b = (r/3) * 3 + c / 3;
  rVis[r][val] = cVis[c][val] = bVis[b][val] = 0;
}

bool solve2(pair<int, int> cell){
  ++ops;
  int r = cell.first, c = cell.second;
  if(r == 9)    return isAllValid();
  if(grid[r][c] != 'x' && isValid(r, c))    return solve2(nextCell(cell));
  else if(grid[r][c] != 'x')  return 0;
  for(char i = '1' ; i <= '9' ; ++i){
    if(!isVis(r, c, i - '0')){
      grid[r][c] = i;           //Do
      visit(r, c, i - '0');
      if(solve2(nextCell(cell))) return 1;      //Recurse
      grid[r][c] = 'x';         //UnDo
      unvisit(r, c, i - '0');
    }
  }
  return 0;
}

bool solve1(pair<int, int> cell){
  ++ops;
  int r = cell.first, c = cell.second;
  if(r == 9)    return isAllValid();
  if(grid[r][c] != 'x' && isValid(r, c))    return solve1(nextCell(cell));
  else if(grid[r][c] != 'x')  return 0;
  for(char i = '1' ; i <= '9' ; ++i){
    grid[r][c] = i;           //Do
    if(isValid(r, c) && solve1(nextCell(cell))) return 1;      //Recurse
    grid[r][c] = 'x';         //UnDo
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
  for(int i = 0 ; i < 9 ; ++i){
    for(int j = 0 ; j < 9 ; ++j){
      if(grid[i][j] != 'x') visit(i, j, grid[i][j] - '0');
    }
  }
  if(solve2({0, 0})) printGrid();
  else puts("INVALID");
  printf("%d\n", ops);
  return 0;
}
