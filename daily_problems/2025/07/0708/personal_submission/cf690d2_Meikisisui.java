import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000003;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        long[] dp = new long[500001];
        dp[0] = 1;
        for (long ez = 1; ez <= n; ez++)
            dp[(int) ez] = (dp[(int) (ez - 1)] * (ez + m - 1) % MOD) * powMod(ez, MOD - 2) % MOD;
        long sum = 0;
        for (long ez = 1; ez <= n; ez++)
            sum = (sum + dp[(int) ez]) % MOD;
        pw.println(sum);
        pw.close();
        br.close();
    }

    private static long powMod(long x, long y) {
        long res = 1;
        long base = x;
        while (y > 0) {
            if ((y & 1) == 1)
                res = res * base % MOD;
            base = base * base % MOD;
            y >>= 1;
        }
        return res;
    }

}
