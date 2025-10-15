import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Constructive {

    FastReader is;
    PrintWriter out;
    String INPUT = "3 2 1\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Constructive().run();
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
        int n = is.ni();
        int a = is.ni();
        int b = is.ni();

        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }

        for (int k = 0; k * a <= n; k++) {
            if ((n - k * a) % b == 0) {
                generate(n, k, a, (n - k * a) / b, b);
                return;
            }
        }

        out.println(-1);
    }

    private void generate(int n, int len1, int a, int len2, int b) {
        int p = 1;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < a; j++) {
                out.print((j + 1) % a + p);
                out.print(' ');
            }
            p += a;
        }
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < b; j++) {
                out.print((j + 1) % b + p);
                out.print(' ');
            }
            p += b;
        }
        out.println();
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

        int ni() {
            return Integer.parseInt(ns());
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
