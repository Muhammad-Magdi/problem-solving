#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
const int N = (1<<17) , M = (1<<14), OO = 0x3f3f3f3f;

int n, q;
int t, a, b;

int parent[N];

int findParent(int x){
	if(parent[x] == x)	return x;
	return parent[x] = findParent(parent[x]);
}

bool sameSet(int a, int b){
	return findParent(a) == findParent(b);
}

void unionSet(int a, int b){
	int pa = findParent(a), pb = findParent(b);
	if(pa == pb)	return;
	parent[pb] = pa;
}

void init(){
	for(int i = 0 ; i <= n ; ++i)	parent[i] = i;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &q);
  init();
  while(q--){
  	scanf("%d %d %d", &t, &a, &b);
  	if(t){		//Make Friends
  		unionSet(a, b);
  	}else{		//Are Friends?
  		printf("%d\n", sameSet(a, b));
  	}
  }
	return 0;
}








