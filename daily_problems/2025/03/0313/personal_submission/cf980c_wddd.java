import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "10 7\n" +
            "187 197 182 185 182 195 188 181 188 182\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Greedy().run();
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
        int k = is.ni();
        int[] ps = is.na(n);

        TreeMap<Integer, Integer> groups = new TreeMap<>();
        for (int p : ps) {
            int min = Math.max(0, p - k + 1);
            Integer prev = groups.floorKey(p);
            if (prev != null) {
                int val = groups.get(prev);
                if (val < min) {
                    out.print(min + " ");
                    groups.put(min, p);
                } else {
                    if (prev + k - 1 >= p) {
                        out.print(prev + " ");
                        groups.put(prev, Math.max(p, val));
                    } else {
                        out.print((val + 1) + " ");
                        groups.put(val + 1, p);
                    }
                }
            } else {
                out.print(min + " ");
                groups.put(min, p);
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

        int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
