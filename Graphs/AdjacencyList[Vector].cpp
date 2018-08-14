#include <cstdio>
#include <vector>

using namespace std;
const int N = 5e4 + 5, M = 1e5+5, OO = 0x3f3f3f3f;

int n, m, u, v;
vector<int> adj[N];

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < m ; ++i){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int u = 0 ; u < n ; ++u){
    printf("Neighbours of %d are:", u);
    for(int v : adj[u]){
      printf(" %d", v);
    }
    puts("");
  }
  return 0;
}
