import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        // dp[ez] 表示以 s[ez-1] 结尾的有效字符串的组合数
        long[] dp = new long[n + 1];
        int[] a = new int[26];
        int[] f = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < 26; ez++) 
            a[ez] = Integer.parseInt(st.nextToken());
        dp[0] = 1;
        int res = Integer.MIN_VALUE;
        for (int ez = 1; ez <= n; ez++) {
            int minX = Integer.MAX_VALUE;
            int vn = ez - 1;
            while (vn >= 0) {
                minX = Math.min(minX, a[s.charAt(vn) - 'a']);
                if (minX < (ez - vn))
                    break;
                else
                    dp[ez] = (dp[ez] + dp[vn]) % MOD;
                vn--;
            }
            res = Math.max(res, ez - vn - 1);
            f[ez] = f[vn + 1] + 1;
        }
        pw.println(dp[n]);
        pw.println(res);
        pw.println(f[n]);
        pw.close();
        br.close();
    }

}
