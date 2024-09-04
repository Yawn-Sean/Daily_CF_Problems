import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static char[] s;
    private static char[] p;
    private static int m, n;
    private static int[] next;
    private static boolean[] back;
    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String sStr = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String tStr = st.nextToken();
        s = sStr.toCharArray();
        p = tStr.toCharArray();
        m = sStr.length();
        n = tStr.length();
        next = new int[n + 1];
        back = new boolean[m + 1];

        kmp();
        long[] dp = new long[m + 1];
        long[] res = new long[m + 1];
        long[] sum = new long[m + 1];
        for (int i = 1; i <= m; i++) {
            if (!back[i])
                dp[i] = dp[i - 1];
            else
                dp[i] = ((i - n + 1) + sum[i - n]) % MOD;
            res[i] = (res[i - 1] + dp[i]) % MOD;
            sum[i] = (sum[i - 1] + res[i]) % MOD;
        }
        pw.println(res[m]);
        pw.close();
        f.close();
    }

    private static void kmp() {
        next[1] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && p[j] != p[i])
                j = next[j - 1];
            if (p[j] == p[i])
                j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < m; i++) {
            while (j > 0 && p[j] != s[i])
                j = next[j - 1];
            if (p[j] == s[i])
                j++;
            if (j == n) {
                j = next[j - 1];
                back[i + 1] = true;
            }
        }
    }

}
