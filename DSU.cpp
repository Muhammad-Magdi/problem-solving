#include <cstdio>
#include <numeric>

using namespace std;
const int N = 1e5+5 , M = (1<<14), OO = 0x3f3f3f3f;

int n, q;
int t, a, b;

int parent[N];
inline void init(){
  iota(parent, parent+N, 0);
}

int findParent(int x){
	if(parent[x] == x)	return x;
	return parent[x] = findParent(parent[x]);
}

inline bool sameSet(int a, int b){
	return findParent(a) == findParent(b);
}

inline void merge(int a, int b){
	a = findParent(a), b = findParent(b);
	if(a == b)	return;
	parent[b] = a;
}


int main(){
	scanf("%d %d", &n, &q);
  init();
  while(q--){
  	scanf("%d %d %d", &t, &a, &b);
  	if(t){		//Make Friends
  		merge(a, b);
  	}else{		//Are Friends?
  		printf("%d\n", sameSet(a, b));
  	}
  }
	return 0;
}
