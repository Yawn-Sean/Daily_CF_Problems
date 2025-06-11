import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(f.readLine());
            long n = Long.parseLong(st.nextToken());
            boolean flagu = false, flagv = false;
            long u = n + 1, v = n;
            flagu = isPrime(u);
            flagv = isPrime(v);
            while (!flagu || !flagv) {
                if (!flagu) {
                    u++;
                    flagu = isPrime(u);
                }
                if (!flagv) {
                    v--;
                    flagv = isPrime(v);
                }
            }
            long a = v * u - 2 * u + 2 * n - 2 * v + 2;
            long b = 2 * u * v;
            long gcd = gcd(a, b);
            pw.println((a / gcd) + "/" + (b / gcd));
        }
        pw.close();
        f.close();
    }

    private static boolean isPrime(long x) {
        if (x < 2)
            return false;
        for (long i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

}
