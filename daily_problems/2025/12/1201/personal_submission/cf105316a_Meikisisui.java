import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] pre = new long[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            long now = Long.parseLong(st.nextToken());
            pre[ez] = pre[ez - 1] + now;
        }
        long total = pre[n];
        long half = (total - 1) / 2;
        long[] dp = new long[n + 1];
        dp[0] = 1;
        int left = 0;
        long sum = dp[0];
        for (int ez = 1; ez <= n; ez++) {
            while (left < ez && pre[left] < pre[ez] - half) {
                sum = (sum - dp[left] + MOD) % MOD;
                left++;
            }
            dp[ez] = sum;
            sum = (sum + dp[ez]) % MOD;
        }
        pw.println(dp[n] % MOD);
        pw.close();
    }

}
