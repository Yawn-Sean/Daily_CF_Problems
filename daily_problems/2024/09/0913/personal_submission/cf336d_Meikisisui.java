import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static long MOD = 1_000_000_007;
    private static long[] fac = new long[200001];
    private static long[] inv = new long[200001];

    private static void pre() {
        fac[0] = 1;
        inv[0] = 1;
        for (int i = 1; i < 200001; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = pow(fac[i], MOD - 2, MOD);
        }
    }

    private static int pow(long x, long n, long mod) {
        long res = 1 % mod;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1) 
                res = res * x % mod;
            x = x * x % mod;
        }
        return (int) res;
    }

    public static long combine(long n, long k) {
        return fac[(int) n] * inv[(int) k] % MOD * inv[(int) (n - k)] % MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        int g = Integer.parseInt(st.nextToken());
        pre();
        if (n == 0) {
            if (g == 0) {
                if (m == 1)
                    pw.println("0");
                else
                    pw.println("1");
            } else {
                if (m == 1)
                    pw.println("1");
                else
                    pw.println("0");
            }
            pw.close();
            f.close();
        } else if (m == 0) {
            if (g == 1) {
                if (n % 2 == 1)
                    pw.println("0");
                else
                    pw.println("1");
            } else {
                if (n % 2 == 1)
                    pw.println("1");
                else
                    pw.println("0");
            }
            pw.close();
            f.close();
        } else {
            long all = combine(n + m, m);
            long ans = 0;
            for (int i = 0; i <= n; i += 2)
                ans = (ans + combine(n - 1 - i + m, m - 1)) % MOD;
            if (m == 1 && (n % 2 == 0))
                ans = (ans - 1 + MOD) % MOD;
            if (m == 1 && (n % 2 == 1))
                ans = (ans + 1) % MOD;
            if (g == 0)
                pw.println(ans);
            else
                pw.println((all - ans + MOD) % MOD);
            pw.close();
            f.close();
        }
    }

}
