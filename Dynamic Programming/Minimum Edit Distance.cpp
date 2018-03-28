#include <bits/stdc++.h>

using namespace std;
const int N = (1<<11) , M = (1<<14), OO = 0x3f3f3f3f;

int mem[N][N];
int n, m;
string s1, s2;

int MED(int i = 0, int j = 0){
	if(i==n)	return m-j;
	if(j==m)	return n-i;
	if(~mem[i][j])	return mem[i][j];
	if(s1[i] == s2[j])	return mem[i][j] = MED(i+1, j+1);
	return mem[i][j] = min(MED(i+1, j), min(MED(i, j+1), MED(i+1, j+1)))+1;
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	cin >> s1 >> s2;
	memset(mem, -1, sizeof mem);
	n = s1.length();
	m = s2.length();
	printf("%d\n", MED());
	return 0;
}
