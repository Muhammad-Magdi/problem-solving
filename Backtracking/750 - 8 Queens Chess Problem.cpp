#include <bits/stdc++.h>

using namespace std;
const int N = 1e2+5 , M = 1e1, OO = 1000000007;
const double EPS = 0.00001;

int t, a, b, Row[10], diff[20], sum[20], sols, ans[10];

void printSolution(){
	if(++sols < 10)	printf(" ");
	printf("%d     ", sols);
	for(int c = 1 ; c < 9 ; ++c)
		printf(" %d", ans[c]);
	puts("");
}

void solve(int c = 1){
	if(c == b){
		solve(c+1);
		return;
	}
	if(c == 9){
		printSolution();
		return;
	}
	for(int r = 1 ; r < 9 ; ++r){
		if(Row[r] || diff[8+r-c] || sum[r+c])	continue;
		Row[r] = diff[8+r-c] = sum[r+c] = 1;		//do
		ans[c] = r;
		solve(c+1);															//recurse
		Row[r] = diff[8+r-c] = sum[r+c] = 0;		//undo
	}
}

void init(){
	memset(Row, 0, sizeof Row);
	memset(sum, 0, sizeof sum);
	memset(diff, 0, sizeof diff);
	memset(ans, 0, sizeof ans);
	sols = 0;
	Row[a] = sum[a+b] = diff[8+a-b] = 1;
	ans[b] = a;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d", &t);
	while(t--){
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		scanf("%d %d", &a, &b);
		init();
		
		solve();
		if(t)	puts("");
	}
  return 0;
}























