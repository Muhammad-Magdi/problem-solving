#include <cstdio>
#include <cstring>

using namespace std;
const int N = 11, M = 1e4 +5, OO = 0x3f3f3f3f;

int n, m;
int visitTime[N][N];

void printPath(){
  puts("---------------------------------");
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      printf("%3d%c", visitTime[i][j], " \n"[j==m-1]);
  puts("---------------------------------");
}

bool valid(int r, int c){   //checks if the cell inside the grid and not visited
  return r < n && r >= 0 && c < m && c >= 0 && visitTime[r][c] == -1;
}

int dr[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc[] = {2, -2, 2, -2, 1, -1, 1, -1};

void solveKT(int r = 0, int c = 0, int visitedNum = 1){
  if(visitedNum == n*m){
    printPath();
  }else{
    for(int k = 0 ; k < 8 ; ++k){   //all the 8 options -directions-
      int nr = r + dr[k], nc = c + dc[k];   //new row, column
      if(valid(nr, nc)){
        visitTime[nr][nc] = visitedNum;   //do
        solveKT(nr, nc, visitedNum+1);    //recurse
        visitTime[nr][nc] = -1;           //undo
      }
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  memset(visitTime, -1, sizeof visitTime);
  visitTime[0][0] = 0;
  solveKT();
  return 0;
}

//sample Input => 3 4
