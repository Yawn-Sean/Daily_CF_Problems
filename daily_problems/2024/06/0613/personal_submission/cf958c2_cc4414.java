// Submission link: https://codeforces.com/contest/958/submission/265584618
class Solution {
    public int solve(int[] a, int k, int p) {
        int n = a.length;
        for (int i = 0; i < a.length; i++) {
            a[i] %= p;
        }
        int[][][] dp = new int[2][k + 1][p];
        int[][] max = new int[2][k + 1];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            Arrays.fill(max[i & 1], 0);
            for (int j = 2; j <= Math.min(i, k); j++) {
                Arrays.fill(dp[i & 1][j], -1);
                for (int m = 0; m < p; m++) {
                    if (dp[(i & 1) ^ 1][j][m] == -1) {
                        continue;
                    }
                    int m1 = (m + a[i - 1]) % p;
                    dp[i & 1][j][m1] = dp[(i & 1) ^ 1][j][m] - m + m1;
                    max[i & 1][j] = Math.max(max[i & 1][j], dp[i & 1][j][m1]);
                }
                dp[i & 1][j][a[i - 1]] = Math.max(dp[i & 1][j][a[i - 1]], max[(i & 1) ^ 1][j - 1] + a[i - 1]);
                max[i & 1][j] = Math.max(max[i & 1][j], dp[i & 1][j][a[i - 1]]);
            }
            Arrays.fill(dp[i & 1][1], -1);
            max[i & 1][1] = (max[(i & 1) ^ 1][1] + a[i - 1]) % p;
            dp[i & 1][1][max[i & 1][1]] = max[i & 1][1];
        }
        return Arrays.stream(dp[n & 1][k]).max().orElse(0);
    }
}
