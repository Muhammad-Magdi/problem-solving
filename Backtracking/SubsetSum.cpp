#include <cstdio>
#include <vector>

using namespace std;
const int N = 25 , M = 1e4 +5, OO = 0x3f3f3f3f;

int n, A[N], x;
vector<int> path;

void printPath(){
  for(int i = 0 ; i < int(path.size()) ; ++i)
    printf("%d%c", path[i], " \n"[i==int(path.size())-1]);
}

void solveSS(int i = 0, int sum = 0){
  if(i == n || sum == x){
    if(sum == x)  printPath();
  }else{
    solveSS(i+1, sum);      //Leave it

    path.push_back(A[i]);   //do
    solveSS(i+1, sum+A[i]); //recurse   -take it-
    path.pop_back();        //undo
  }
}

int main(){
  scanf("%d %d", &n, &x);
  for(int i = 0 ; i < n ; ++i)    scanf("%d", A+i);
  solveSS();
  return 0;
}
