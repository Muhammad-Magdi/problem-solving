//Spoj CSTREET
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5, M = 3e5+5, OO = 0x3f3f3f3f;

struct edge{
  int f, t, c;
  bool operator <(const edge& e)const{
    return c < e.c;
  }
}E[M];
int sorted[M];

int t, p, n, m, u, v, c, total;

int par[N];
inline void init(){
  iota(par, par+n, 0);
}

inline int find(int u){
  return par[u] == u ? u : par[u] = find(par[u]);
}

inline bool sameSet(int a, int b){
  return find(a) == find(b);
}

inline void join(int a, int b){
  a = find(a), b = find(b);
  if(a == b)  return;
  par[a] = b;
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &p, &n, &m);
    init();
    for(int i = 0 ; i < m ; ++i){
      scanf("%d %d %d", &u, &v, &c);
      E[i] = {--u, --v, c};
      sorted[i] = i;
    }
    sort(sorted, sorted+m, [](const int& a, const int& b){
      return E[a] < E[b];
    });
    total = 0;
    for(int i = 0 ; i < m ; ++i){
      int idx = sorted[i];
      if(!sameSet(E[idx].f, E[idx].t)){
        join(E[idx].f, E[idx].t);
        total += E[idx].c;
      }
    }
    printf("%d\n", p*total);
  }
  return 0;
}
