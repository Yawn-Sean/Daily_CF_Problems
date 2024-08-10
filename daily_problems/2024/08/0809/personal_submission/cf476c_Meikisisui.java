import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        int res = dreamoon(a, b);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long MOD = 1_000_000_007;

    private static int dreamoon(long a, long b) {
        long a1 = ((a * (a - 1)) / 2) % MOD;
        long b1 = ((b * (b - 1)) / 2) % MOD;
        a1 = (a1 * b) % MOD;
        long res = (a1 + ((a * (b + 1)) % MOD)) % MOD;
        res = (res * b1) % MOD;
        return (int) res;
    }

}
