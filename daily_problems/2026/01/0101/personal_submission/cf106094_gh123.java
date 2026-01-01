import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C106094 {

     static final int MAX_X = 200005;
    static int[] spf = new int[MAX_X];

    public static void main(String[] args) throws IOException {
    for (int i = 0; i < MAX_X; i++) spf[i] = i;
        for (int i = 2; i * i < MAX_X; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAX_X; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        FastReader fr = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = fr.nextInt();
        while (t-- > 0) {
            int x = fr.nextInt();
            long k = fr.nextLong();

            // Factorize x and store exponents
            List<Long> cnt = new ArrayList<>();
            while (x > 1) {
                int p = spf[x];
                long c = 0;
                while (x % p == 0) {
                    x /= p;
                    c++;
                }
                cnt.add(c);
            }

            int l = 0, r = 62;
            int ans = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (check(mid, k, cnt)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            out.println(ans);
        }
        out.flush();
        out.close();
    }

    private static boolean check(int ans, long k, List<Long> cnt) {
        if (ans == 0) return true;
        long target = 1L << ans;
        long needed = 0;
        for (long q : cnt) {
            long rem = q % target;
            if (rem != 0) {
                needed += (target - rem);
                if (needed > k) return false;
            }
        }
        return needed <= k;
    }

    static class FastReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastReader(InputStream input) {
            reader = new BufferedReader(new InputStreamReader(input));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreElements()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    return null;
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
    }
}
