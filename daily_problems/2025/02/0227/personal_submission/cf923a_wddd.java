import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math3 {

    FastReader is;
    PrintWriter out;
    String INPUT = "14";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math3().run();
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
        int x2 = is.ni();
        int[] maxPFs = maxPrimeFactor(x2);

        int nextMin = getNextMinX(x2, maxPFs);
        int minX0 = Integer.MAX_VALUE;
        for (int i = nextMin; i <= x2; i++) {
            minX0 = Math.min(minX0, getNextMinX(i, maxPFs));
        }

        out.println(minX0);
    }

    private int getNextMinX(int x, int[] maxPFs) {
        return maxPFs[x] == x ? x : x - maxPFs[x] + 1;
    }

    public int[] maxPrimeFactor(int n) {
        int[] pf = new int[n + 1];
        for (int i = 0; i < pf.length; i++) {
            pf[i] = i;
        }

        for (int i = 2; i < pf.length; i++) {
            if (pf[i] == i) {
                for (int j = i + i; j < pf.length; j += i) {
                    pf[j] = i;
                }
            }
        }

        return pf;
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
