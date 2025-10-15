package codeforces.C38_E_LetsGoRolling;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class DP {

    void solve() {
        int n = is.ni();
        long[][] marbles = is.nml(n, 2);
        Arrays.sort(marbles, Comparator.comparingLong(i -> i[0]));

        long[][] dp = new long[n][2];
        for (long[] row : dp) {
            Arrays.fill(row, Long.MAX_VALUE / 2);
        }
        dp[0][0] = marbles[0][1];
        dp[0][1] = Long.MAX_VALUE / 2;

        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1]) + marbles[i][1];

            long sum = 0;
            for (int j = i - 1; j >= 0; j--) {
                sum += marbles[j + 1][0];
                dp[i][1] = Math.min(dp[i][1], dp[j][0] + sum - (i - j) * marbles[j][0]);
            }
        }

        out.println(Math.min(dp[n - 1][0], dp[n - 1][1]));
    }

}
