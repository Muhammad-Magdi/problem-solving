#include <bits/stdc++.h>

using namespace std;
const int N = 19 , M = 1e3+5, OO = 0x3f3f3f3f, MOD = 1e9+7;

typedef long long ll;

inline ll fixMod(ll a, ll m){
  return (a%m + m)%m;
}

//a = q*b + r
//q = (a-r)/b
inline ll floor(ll a, ll b){
  return (a - fixMod(a, b))/b;
}

inline void update(ll& t0, ll& t1, ll q){
  ll t2 = t0 - q*t1;
  t0 = t1;
  t1 = t2;
}

//Extended Euclidean Algorithm
//a*x + b*y = g
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

//Linear Diophantine Equation
//a*x + b*y = c
bool solveLDE(ll a, ll b, ll c, ll& x, ll& y, ll& g){
  g = eGCD(a, b, x, y);
  x *= c/g;
  y *= c/g;
  return !(c%g);
}

//if gcd(a, m) = 1 -i.e. Coprimes-, returns true
//(a*x)%m = 1
//a*x - m*q = 1
bool modInverse(ll a, ll m, ll& inv){
  ll temp;
  ll g = eGCD(a, m, inv, temp);
  inv = fixMod(inv, m);
  return g == 1;
}

int main(){

  return 0;
}
