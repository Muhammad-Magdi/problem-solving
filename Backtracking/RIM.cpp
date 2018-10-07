#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int N = 10 , M = 1e4 +5, OO = 0x3f3f3f3f;

int n, m;
char grid[N][N];

bool valid(int r, int c){   //inside the grid and not equal #
  return (r<n && r>=0 && c<m && c>=0 && grid[r][c]!='#');
}

string path;

void printPath(){
  printf("%s\n", path.c_str());
}

bool solveRIM(int r = 0, int c = 0){
  if(r == n-1 && c == m-1){
    printPath();
  }else{
    if(valid(r+1, c)){     //Down
      path.push_back('D');        //do
      solveRIM(r+1, c);           //recurse
      path.pop_back();            //undo
    }
    if(valid(r, c+1)){    //Right
      path.push_back('R');        //do
      solveRIM(r, c+1);           //recurse
      path.pop_back();            //undo
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < n ; ++i)
      scanf("%s", grid[i]);
  solveRIM();
  return 0;
}
