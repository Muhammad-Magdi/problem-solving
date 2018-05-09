#include <bits/stdc++.h>

using namespace std;
const int N = 22 , OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int a, b, c;
long long A[N][N][N];
long long bestSum;

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	scanf("%d %d %d", &a, &b, &c);
	for(int i = 1 ; i <= a ; ++i){
		for(int j = 1 ; j <= b ; ++j){
			for(int k = 1 ; k <= c ; ++k){
				scanf("%lld", A[i][j]+k);
				A[i][j][k] += A[i-1][j][k] + A[i][j-1][k] - A[i-1][j-1][k];	//Cummulative grids
			}
		}
	}
	for(int sa = 1 ; sa <= a ; ++sa)for(int ea = sa ; ea <= a ; ++ea){
		for(int sb = 1 ; sb <= b ; ++sb)for(int eb = sb ; eb <= b ; ++eb){
			long long sum = 0;
			for(int i = 1 ; i <= c ; ++i){
				sum += A[ea][eb][i] - A[sa-1][eb][i] - A[ea][sb-1][i] + A[sa-1][sb-1][i];
				sum = max(sum, 0ll);						//Does it worth?
				bestSum = max(bestSum, sum);		//Is it the best?
			}
		}
	}
	printf("%lld\n", bestSum);
	return 0;
}
