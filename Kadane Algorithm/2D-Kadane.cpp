#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n, m;
int A[N][N];
long long bestSum;

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d", A[i]+j);
			A[i][j] += A[i-1][j];			//Cummulative Columns.
		}
	}
	for(int top = 1 ; top <= n ; ++top){
		for(int btm = top ; btm <= n ; ++btm){
			long long sum = 0;
			for(int i = 1 ; i <= m ; ++i){
				sum += A[btm][i] - A[top-1][i];	//Add current element -Column-
				sum = max(sum, 0ll);							//Does it worth?
				bestSum = max(bestSum, sum);		//Is it the best?
			}
		}
	}
	printf("%lld\n", bestSum);
	return 0;
}
