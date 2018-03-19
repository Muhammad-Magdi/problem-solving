#include <bits/stdc++.h>

using namespace std;
const int N = (1<<20) , M = (1<<16), OO = 0x3f3f3f3f;

int Coins[] = {5, 10, 25, 50, 100};
long long mem[N][10];
int n;

/*
long long solve(int i = 0, int rem = n){			//O(n*5)
	if(i==5)	return rem==0;
	return solve(i+1, rem) + (rem>=Coins[i]? solve(i, rem-Coins[i]) : 0);
}
*/

long long coinChange(int rem = n, int startCoin = 0){						//O(n*5)
	if(!rem)	return 1;
	long long & ret = mem[rem][startCoin];
	if(~ret)	return ret;
	ret = 0;
	for(int coin = startCoin ; coin < 5 ; ++coin)
		ret += (rem>=Coins[coin]? coinChange(rem-Coins[coin], coin) : 0);
	return ret;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	memset(mem, -1, sizeof mem);
	scanf("%d", &n);
	printf("%lld\n", coinChange());
	return 0;
}
