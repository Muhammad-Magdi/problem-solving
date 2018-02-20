#include <iostream>

using namespace std;
const int N = 1e5 + 5, M = 1e8, OO = 2000000007;

int greatestPF[N];
int n;

void sieve(){
  greatestPF[0] = greatestPF[1] = 1;
  for(int i = 2 ; i*i <= n ; ++i){
    if(!greatestPF[i])  for(int j = i ; j < n ; j+=i){
      greatestPF[j] = i;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  n = N;
  int x;
  sieve();
  for(int i = 0 ; i < n ; ++i){
    scanf("%d", &x);
		printf("Prime Factors of %d are :\n", x);
    while(x>1){
      printf("%d ", greatestPF[x]);
      x /= greatestPF[x];
    }
    puts("");
  }
  return 0;
}
