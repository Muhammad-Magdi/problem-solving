#include <cstdio>

using namespace std;

typedef long long ll;

//Euler phi function
//The number of coprimes with n that are < n
ll phi(ll n){     //O(sqrt(n))
  ll res = n;
  for(ll i = 2 ; i <= n/i ; i += 1 + (i&1)){
    if(!(n%i)){
      while(!(n%i)) n /= i;
      res -= res/i;
    }
  }
  if(n > 1) res -= res/n;
  return res;
}

//Iterative fast power
//b^p = (b^(p/2))^2
ll fPower(ll b, ll p, ll m){    //O(log(p))
  ll res = 1;
  while(p){
    if(p&1) res = (res * x)%m;
    x = (x * x)%m;
    p >>= 1;
  }
  return res;
}

//Euler => a^(phi(m)) = a mod m
//Euler => a^(phi(m)-1) = 1 mod m
//Iff a and m are coprimes
inline ll modInversePHI(ll a, ll m){     //O(sqrt(m))
  return fPower(a, phi(m)-1, m);
}

//Fermat => a^(p-1) = a mod p
//Fermat => a^(p-2) = 1 mod p
//Iff p is prime
inline ll modInversePrime(ll a, ll p){     //O(log(p))
  return fPower(a, p-2, p);
}

int main(){

  return 0;
}
