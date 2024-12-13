import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long n = Long.valueOf(st.nextToken());
        long k = Long.valueOf(st.nextToken());
        st = new StringTokenizer(f.readLine());
        long a = Long.valueOf(st.nextToken());
        long b = Long.valueOf(st.nextToken());
        long mn = Long.MAX_VALUE, mx = 0;
        long l1 = b - a, l2 = k - b - a;
        if (l1 < 0)
            l1 += k;
        if (l2 < 0)
            l2 += k;
        for (long ez = 1; ez <= k + 1; ez++) {
            if (Math.min(ez - 1, k + 1 - ez) != a)
                continue;
            for (long vn = 1; vn <= k; vn++) {
                long x = (ez + vn - 1) % (n * k) + 1;
                if (Math.min((x - 1) % k, k - (x - 1) % k) != b)
                    continue;
                for (long w = vn; w <= n * k; w += k) {
                    long tmp = n * k / gcd(w, n * k);
                    mn = Math.min(mn, tmp);
                    mx = Math.max(mx, tmp);
                }
            }
        }
        pw.println(mn + " " + mx);
        pw.close();
        f.close();
    }

    private static long gcd(long x, long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

}
