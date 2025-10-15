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
        long n = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        if (n == 0) {
            pw.println(0);
            pw.close();
            f.close();
        }
        long x = 2 * n - 1;
        long e = exp(2, k);
        pw.println((x % MOD * e % MOD + 1) % MOD);
        pw.close();
        f.close();
    }

    public static long exp(long x, long e) {
        long res = 1;
        while (e > 0) {
            if ((e & 1) == 1)
                res = (res * x) % MOD;
            e >>= 1;
            x = (x * x) % MOD;
        }
        return res;
    }

}
