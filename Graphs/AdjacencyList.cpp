#include <cstring>
#include <cstdio>

using namespace std;
const int N = 5e4 + 5, M = 1e5+5, OO = 0x3f3f3f3f;

int ne, head[N], nxt[M], to[M];
int n, m, u, v;

void init(){
  memset(head, -1, n*sizeof head[0]);
  ne = 0;
}

void addEdge(int f, int t){
  nxt[ne] = head[f];
  to[ne] = t;
  head[f] = ne++;
}

void addBiEdge(int a, int b){
  addEdge(a, b);
  addEdge(b, a);
}


int main(){
  scanf("%d %d", &n, &m);
  init();
  for(int i = 0 ; i < m ; ++i){
    scanf("%d %d", &u, &v);
    addBiEdge(u, v);
  }
  for(int u = 0 ; u < n ; ++u){
    printf("Neighbours of %d are:", u);
    for(int k = head[u] ; ~k ; k = nxt[k]){
      int v = to[k];
      printf(" %d", v);
    }
    puts("");
  }
  return 0;
}
