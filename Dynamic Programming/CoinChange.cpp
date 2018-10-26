#include <bits/stdc++.h>

using namespace std;
const int N = (1<<20) , M = (1<<16), OO = 0x3f3f3f3f;

int n;
int Coins[] = {5, 10, 25, 50, 100};
long long mem[5][N];

long long solve(int i = 0, int rem = n){			//O(n*n)
	if(i==5)	return rem == 0;
	long long& ret = mem[i][rem];
	if(~ret)	return ret;
	return ret = (rem>=Coins[i]? solve(i, rem-Coins[i]) : 0) + solve(i+1, rem);
}

int main(){
	memset(mem, -1, sizeof mem);
	scanf("%d", &n);
	printf("%lld\n", solve());
	return 0;
}
