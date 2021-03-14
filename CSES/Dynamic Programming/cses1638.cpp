#include <cstdio>
 
using namespace std;
 
const int N = 1e3+3, MOD = 1e9+7;
 
int n;
char A[N][N];
int dp[N];
 
int main() {
    scanf("%d", &n);
    for (int r = 0; r < n; r++) {
        scanf("%s", A[r]);
    }
    dp[n-1] = (A[n-1][n-1] == '.');
    for (int r = n-1; ~r; r--) {
        for (int c = n-1; ~c; c--) {
            if (A[r][c] != '.') {
                dp[c] = 0;
                continue;
            }
            dp[c] = (dp[c] + dp[c+1]);
            if (dp[c] >= MOD) {
                dp[c] -= MOD;
            }
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}
