import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Math1_Submit {

    FastReader is;
    PrintWriter out;
    String INPUT = "5\n" +
            "1\n" +
            "11\n" +
            "16\n" +
            "123456\n" +
            "1000000000000000000\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math1_Submit().run();
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
        int t = is.ni();
        for (int i = 0; i < t; i++) {
            long k = is.nl();
            sameKeys(k);
        }
    }

    private void sameKeys(long k) {
        TreeMap<Integer, Integer> fps = new TreeMap<>();
        int total = 0;
        int d = 2;
        while (k > 0) {
            fps.put((int) (k % d), fps.getOrDefault((int) (k % d), 0) + 1);
            k /= d;
            d++;
            total++;
        }

        long keys = countKeys(fps, total);
        if (fps.containsKey(0)) {
            fps.put(0, fps.get(0) - 1);
            if (fps.get(0) == 0) {
                fps.remove(0);
            }
            keys -= countKeys(fps, total - 1);
        }
        out.println(keys - 1);
    }

    private long countKeys(TreeMap<Integer, Integer> fps, int total) {
        long count = 1;
        int prev = 0;
        for (Integer key = fps.lastKey(); key != null; key = fps.floorKey(key - 1)) {
            int valid = total - prev - Math.max(key - 1, 0);
            count *= valid < fps.get(key) ? 0 : comb(valid, fps.get(key));
            prev += fps.get(key);
        }
        return count;
    }

    public static long comb(int n, int r) {
        if (n - r < r) {
            return comb(n, n - r);
        }

        long result = 1;
        for (int i = 0; i < r; i++) {
            result *= n - r + i + 1;
            result /= i + 1;
        }
        return result;
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
