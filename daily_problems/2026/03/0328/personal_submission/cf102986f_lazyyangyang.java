import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int M = 1000005;
        final int MOD = 998244353;

        long[] mis = new long[M];
        long[] dp = new long[M];

        mis[0] = 1;
        for (int i = 2; i < M; i++) {
            mis[i] = (long) (i - 1) * (mis[i - 1] + mis[i - 2]) % MOD;
        }

        for (int i = 3; i < M; i++) {
            dp[i] = (dp[i - 1] + (long) (i - 1) * mis[i - 1]) % MOD;
            dp[i] = dp[i] * i % MOD;
        }

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            bw.write(dp[n] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
