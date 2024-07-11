import java.util.*;
import java.io.*;

public class Main {

    static int MOD = (int) 1e9 + 7;

    static void solve() {
        int n = sc.nextInt();
        char[] str = sc.next().toCharArray();
        int[][] comm = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; i--) {
            comm[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                comm[i][j] = str[i] == str[j] ? (1 + comm[i + 1][j + 1]) : 0;
            }
        }
        long[][] dp = new long[n + 1][n + 2];
        for (int i = 0; i <= n; i++) {
            dp[n][i] = 1;
        }
        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '0') {
                continue;
            }
            for (int j = n - i - 1; j > 0; j--) {
                dp[i][j] = (dp[i + j + 1][j + 1] + dp[i][j + 1]) % MOD;
            }
            for (int j = Math.min(i, n - i); j > 0; j--) {
                int t = comm[i - j][i];
                if (t < j && str[i - j + t] < str[i + t]) {
                    dp[i][j] = (dp[i][j] + dp[i + j][j]) % MOD;
                }
            }
            ans += dp[i][i];
        }
        out.println((ans + 1) % MOD);
    }

}
