#include <bits/stdc++.h>

using namespace std;
const int N = 19 , M = 1e3+5, OO = 0x3f3f3f3f;

typedef long long ll;

inline ll fixMod(ll a, ll m){
  return (a%m + m)%m;
}

inline void update(ll& t0, ll& t1, ll q){
  ll t2 = t0 - q*t1;
  t0 = t1;
  t1 = t2;
}

//Extended Euclidean Algorithm
// a*x + b*y = g
ll eGCD(ll g0, ll g1, ll& x0, ll& y0){
  ll x1 = y0 = 0, y1 = x0 = 1;
  while(g1){
    ll q = g0/g1;
    update(g0, g1, q);
    update(x0, x1, q);
    update(y0, y1, q);
  }
  return g0;
}

//if gcd(a, m) = 1 -i.e. Coprimes-, returns true
bool modInverse(ll a, ll m, ll& inv){
  ll temp;
  ll g = eGCD(a, m, inv, temp);
  return g == 1;
}

//(51*10 + 7) = 517
inline void addLDigit(ll& h, char d, ll base, ll mod){
	h = ((h * base)%mod + d)%mod;
}

//(517 - 7)/10 = 51
inline void remLDigit(ll& h, char d, ll inv, ll mod){
	h =	(fixMod(h-d, mod) * inv)%mod;
}

//17 + 5*100 = 517
inline void addMDigit(ll& h, ll p, char d, ll mod){
	h = (h + (p*d)%mod)%mod;
}

//517 - 500 = 17
inline void remMDigit(ll& h, ll p, char d, ll mod){
	h = fixMod(h-(d*p)%mod, mod);
}


int main(){

  return 0;
}
