import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {
    
    private static int MOD = 1_000_000_007;
    private static final int maxn = 5_000_001;
    static long[] dp = new long[maxn];
    static int[] prime = new int[maxn];

    // 预处理素数筛求每个数最小素数因子用于分组
    private static void IsPrime() {
        prime[2] = 2;
        for (int i = 2; i < maxn; i++)
            prime[i] = i;
        for (int i = 2; i * i < maxn; i++)
            if (prime[i] == i)
                for (int j = i * i; j < maxn; j += i)
                    prime[j] = Math.min(i, prime[j]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        IsPrime();
        dp[1] = 0;
        for (int i = 2; i <= r; i++) {
            dp[i] = Long.MAX_VALUE;
            for (int j = i; j != 1; j /= prime[j])
                dp[i] = Math.min(dp[i], dp[i / prime[j]] + (long) i * (prime[j] - 1) / 2);
        }
        long ans = 0;
        long cnt = 1;
        for (int i = l; i <= r; i++) {
            dp[i] %= MOD;
            ans += dp[i] * cnt;
            cnt *= t;
            cnt %= MOD;
            ans %= MOD;
        }
        pw.println((ans + MOD) % MOD);
        pw.close();
        f.close();
    }

}
