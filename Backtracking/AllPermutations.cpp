#include <cstdio>
#include <vector>

using namespace std;
const int N = 12 , M = 1e4 +5, OO = 0x3f3f3f3f;

int n, A[N], sitted[N];
vector<int> permutation;

void printPath(){
  for(int i = 0 ; i < n ; ++i)
    printf("%d%c", permutation[i], " \n"[i==n-1]);
}

void solveAP(int idx = 0){
  if(idx == n){
    printPath();
  }else{
    for(int i = 0 ; i < n ; ++i){
      if(!sitted[i]){
        sitted[i] = 1;               //do
        permutation.push_back(A[i]); //do
        solveAP(idx+1);              //recurse
        sitted[i] = 0;               //undo
        permutation.pop_back();      //undo
      }
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)
    scanf("%d", A+i);
  solveAP();
  return 0;
}
