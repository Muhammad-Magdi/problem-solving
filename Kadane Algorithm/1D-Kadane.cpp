#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n;
int A[N];
long long sum, bestSum;

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i)
			scanf("%d", A+i);
	for(int i = 0 ; i < n ; ++i){
		sum += A[i];
		sum = max(sum, 0ll);
		bestSum = max(bestSum, sum);
	}
	printf("%lld\n", bestSum);
	return 0;
}
