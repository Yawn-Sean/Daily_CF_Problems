import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][2];
        dp[0][0] = 1;
        for (int ez = 1; ez < n; ez++) {
            int tmp = 0;
            tmp++;
            tmp += dp[ez - 1][ez % 2];
            tmp += dp[ez - 1][(ez + 1) % 2];
            tmp %= MOD;
            dp[ez][ez % 2] = tmp;
            dp[ez][(ez + 1) % 2] = dp[ez - 1][(ez + 1) % 2];
        }
        int res = (dp[n - 1][0] + dp[n - 1][1]) % MOD;
        pw.println(res);
        pw.close();
    }

}
