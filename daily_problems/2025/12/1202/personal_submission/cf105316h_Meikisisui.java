import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 998244353;
    private static int len = 100000;
    private static long[] dp = new long[len + 2];
    private static long[] sum = new long[len + 2];

    private static void precompute() {
        dp[1] = 1;
        for (int ez = 2; ez <= len; ez++)
            dp[ez] = MOD - MOD / ez * dp[MOD % ez] % MOD;
        sum[0] = 0;
        for (int ez = 1; ez <= len; ez++)
            sum[ez] = (sum[ez - 1] + dp[ez]) % MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        precompute();
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long res = ((n + 1) * sum[n] % MOD - n + MOD) % MOD;
            pw.println(res);
        }
        pw.close();
    }

}
