import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        char[] s = st.nextToken().toCharArray();
        st = new StringTokenizer(br.readLine());
        char[] t = st.nextToken().toCharArray();
        int m = s.length, n = t.length;
        long dp[][] = new long[m + 1][n + 1];
        for (int ez = 0; ez < m; ez++) {
            for (int vn = 0; vn < n; vn++)
                dp[ez + 1][vn + 1] = dp[ez + 1][vn] + ((s[ez] == t[vn]) ? (dp[ez][vn] + 1) : 0) % MOD;
        }
        long res = 0;
        for (int ez = 0; ez < m; ez++)
            res = (res + dp[ez + 1][n]) % MOD;
        pw.println(res);
        pw.close();
    }

}
