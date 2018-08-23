#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5, OO = 0x3f3f3f3f;

typedef long long ll;

ll phi[N];
void phiSieve(){
  iota(phi, phi+N, 0);
  for(ll i = 2 ; i < N ; i += 1 + (i&1))
    if(phi[i] == i)
      for(ll j = i ; j < N ; j+=i)
        phi[j] -= phi[j]/i;
}

int main(){
  phiSieve();
  for(int i = 0 ; i < 100 ; ++i){
    printf("%d -> %lld\n", i, phi[i]);
  }
  return 0;
}
