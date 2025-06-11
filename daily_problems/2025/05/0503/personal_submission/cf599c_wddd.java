import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "2 1 3 2";

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
        int[] hs = is.na(n);

        int[] sorted = hs.clone();
        Arrays.sort(sorted);

        Map<Integer, Integer> heightToFirstInd = new HashMap<>();
        for (int i = 0; i < sorted.length; i++) {
            if (!heightToFirstInd.containsKey(sorted[i])) {
                heightToFirstInd.put(sorted[i], i);
            }
        }

        int partitions = 0;
        int right = 0;
        for (int i = 0; i < hs.length; i++) {
            right = Math.max(right, i);

            int expectedInd = heightToFirstInd.get(hs[i]);
            right = Math.max(right, expectedInd);
            heightToFirstInd.put(hs[i], expectedInd + 1);

            if (right <= i) {
                partitions++;
            }
        }

        out.println(partitions);
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
