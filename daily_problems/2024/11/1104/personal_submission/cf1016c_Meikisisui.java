import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] aa = new long[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            aa[ez] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        long[] bb = new long[n];
        for (int ez = 0; ez < n; ez++)
            bb[ez] = Long.parseLong(st.nextToken());
        long[] dp = new long[n + 1];
        for (int ez = 0; ez < n; ez++) {
            if (ez % 2 == 0)
                dp[ez + 1] = dp[ez] + ez * 2 * aa[ez] + (ez * 2L + 1) * bb[ez];
            else
                dp[ez + 1] = dp[ez] + ez * 2 * bb[ez] + (ez * 2L + 1) * aa[ez];
        }
        long[] back = new long[n + 1];
        for (int ez = n - 1; ez >= 0; ez--)
            back[ez] += aa[ez] + bb[ez] + back[ez + 1];
        long qa = 0, qb = 0;
        long[] dq = new long[n + 1];
        for (int ez = n - 1; ez >= 0; ez--) {
            long m = (n - 1 - ez) * 2L + 1;
            qa += back[ez + 1] + m * bb[ez];
            qb += back[ez + 1] + m * aa[ez];
            dq[ez] = ez % 2 == 0 ? qa : qb;
        }
        long res = 0;
        for (int ez = 0; ez <= n; ez++) {
            long w = dp[ez] + back[ez] * ez * 2 + dq[ez];
            res = Math.max(res, w);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
