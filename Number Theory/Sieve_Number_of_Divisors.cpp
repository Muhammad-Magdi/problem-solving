#include <iostream>

using namespace std;
const int N = 1e5 + 5, M = 1e8, OO = 2000000007;

int numberOfDivisors[N];
int n;

void sieve(){
  numberOfDivisors[0] = numberOfDivisors[1] = 1;
  for(int i = 2 ; i*i <= n ; ++i){
    if(!numberOfDivisors[i])  for(int j = i ; j < n ; j+=i){
      int e = 0;
      int q = j;
      while(q%i==0){
        ++e;
        q/=i;
      }
      if(numberOfDivisors[j]) numberOfDivisors[j]*=(e+1);
      else  numberOfDivisors[j] = e+1;
    }
  }
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
  n = N;
  sieve();
  for(int i = 2 ; i <= 30 ; ++i){		//Note that Primes have exactly 2 divisors
  	printf("Number %d has %d Divisors\n", i, numberOfDivisors[i]);
  }
  return 0;
}
