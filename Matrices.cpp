#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define row vector<ll>
#define matrix vector<row>
#define ROWS(v)  (v).size()
#define COLS(v)  (v)[0].size()

const int N = 5e4+5, OO = 0x3f3f3f3f, MOD = 1e9+7;

inline ll fixMod(ll a, ll m){
  return (a%m+m)%m;
}

void printMatrix(const matrix& m){
  for(auto r : m){
    for(auto x : r){
      cout << x << " ";
    }
    cout << endl;
  }
}

matrix identity(int n){
  matrix ret(n ,row(n, 0));
  for(int i = 0 ; i < n ; ++i)  ret[i][i] = 1;
  return ret;
}

matrix add(const matrix& a, const matrix& b){
  matrix ret(ROWS(a), row(COLS(a), 0));
  for(int i = 0 ; i < ROWS(a) ; ++i)
    for(int j = 0 ; i  < COLS(a) ; ++j)
      ret[i][j] = a[i][j] + b[i][j];
  return ret;
}

matrix multiply(const matrix& a, const matrix& b){
  matrix ret(ROWS(a), row(COLS(b), 0));
  for(int r = 0 ; r < ROWS(a) ; ++r)
    for(int k = 0 ; k < COLS(a) ; ++k)
      if(a[r][k])for(int c = 0 ; c < COLS(b) ; ++c)
        ret[r][c] = (ret[r][c] + (a[r][k]*b[k][c])%MOD)%MOD;
  return ret;
}

matrix power(const matrix& a, ll p){
  if(!p)  return identity(ROWS(a));
  matrix m = power(a, p>>1);
  m = multiply(m, m);
  if(p&1) m = multiply(m, a);
  return m;
}

matrix powerI(const matrix& a, ll p){
  matrix ret = identity(ROWS(a)), t = a;
  while(p){
    if(p&1) ret = multiply(ret, t);
    t = multiply(t, t);
    p >>= 1;
  }
  return ret;
}

int main(){

  return 0;
}
