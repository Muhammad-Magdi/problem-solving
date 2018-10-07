#include <cstdio>

using namespace std;
const int N = 15 , M = 1e4 +5, OO = 0x3f3f3f3f;

int n;
bool col[N], md[2*N], sd[2*N];
char board[N][N];

void printGrid(){
  puts("---------------------------------");
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0; j < n ; ++j)
      printf("%c", board[i][j]);
    puts("");
  }
  puts("---------------------------------");
}

bool valid(int r, int c){
  return (!col[c] && !md[r-c+N] && !sd[r+c]);
}

void solveNQ(int r = 0){
  if(r == n){
    printGrid();
  }else{
    for(int c = 0 ; c < n ; ++c){
      if(valid(r, c)){
        col[c] = md[r-c+N] = sd[r+c] = 1;     //do
        board[r][c] = 'Q';                    //do
        solveNQ(r+1);                         //recurse
        col[c] = md[r-c+N] = sd[r+c] = 0;     //undo
        board[r][c] = '.';                    //undo
      }
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)  board[i][j] = '.';
  solveNQ();
  return 0;
}
