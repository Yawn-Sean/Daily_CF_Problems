import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BruteForce2 {

    FastReader is;
    PrintWriter out;
    String INPUT = "10";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BruteForce2().run();
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

        BigInteger curr = BigInteger.TWO;
        BigInteger root = BigInteger.TWO;
        BigInteger k = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            while (true) {
                BigInteger diff = root.pow(2).subtract(curr);
                if (root.mod(k.add(BigInteger.ONE)).equals(BigInteger.ZERO) && diff.mod(k).equals(BigInteger.ZERO)) {
                    out.println(diff.divide(k));
                    curr = root;
                    root = root.divide(k).add(BigInteger.ONE).multiply(k);
                    k = k.add(BigInteger.ONE);
                    break;
                } else {
                    root = root.divide(k).add(BigInteger.ONE).multiply(k);
                }
            }
        }
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
