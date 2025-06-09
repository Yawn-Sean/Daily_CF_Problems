import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math1 {

    FastReader is;
    PrintWriter out;
    // String INPUT = "2 2 1 0 0 1\n";
    // String INPUT = "2 2 10 11 0 1\n";
    // String INPUT = "2 4 3 -1 3 7\n";
    String INPUT = "2 4 3 -1 1 0\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math1().run();
    }

    void run() throws Exception {
        is = oj ? new FastReader(System.in) : new FastReader(new ByteArrayInputStream(INPUT.getBytes()));
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        objTr(System.currentTimeMillis() - s + "ms");
        out.close();
    }

    void solve() {
        long a = is.nl();
        long b = is.nl();
        long x1 = is.nl();
        long y1 = is.nl();
        long x2 = is.nl();
        long y2 = is.nl();

        long min1 = Math.min(y1 - x1, y2 - x2);
        long max1 = Math.max(y1 - x1, y2 - x2);
        long k1 = (long) Math.floor((double) min1 / (2 * b));
        long k2 = (long) Math.ceil((double) max1 / (2 * b));
        if (k1 * (2 * b) <= min1) {
            k1++;
        }
        if (k2 * (2 * b) >= max1) {
            k2--;
        }

        long min2 = Math.min(y1 + x1, y2 + x2);
        long max2 = Math.max(y1 + x1, y2 + x2);
        long k3 = (long) Math.floor((double) min2 / (2 * a));
        long k4 = (long) Math.floor((double) max2 / (2 * a));
        if (k3 * (2 * a) <= min2) {
            k3++;
        }
        if (k4 * (2 * a) >= max2) {
            k4--;
        }

        long count1 = Math.max(0, k2 - k1 + 1);
        long count2 = Math.max(0, k4 - k3 + 1);
        
        out.println(Math.max(count1, count2));
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String ns() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        long nl() {
            return Long.parseLong(ns());
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
