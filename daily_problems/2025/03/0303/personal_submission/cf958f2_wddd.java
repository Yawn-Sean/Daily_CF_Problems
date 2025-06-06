import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SlidingWindow {

    FastReader is;
    PrintWriter out;
//    String INPUT = "8 3\n" +
//            "3 3 1 2 2 1 1 3\n" +
//            "3 1 1\n";
//    String INPUT = "6 5\n" +
//            "1 2 4 2 4 3\n" +
//            "0 0 1 0 0\n";
    String INPUT = "2 2\n" +
        "2 2\n" +
        "1 1";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new SlidingWindow().run();
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
        int m = is.ni();
        int[] knights = is.na(n);
        int[] counts = is.na(m);

        int total = 0;
        int required = 0;
        for (int c : counts) {
            total += c;
            if (c != 0) {
                required++;
            }
        }

        int minLen = knights.length;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (required == 0) {
                int toRemove = knights[left] - 1;
                counts[toRemove]++;
                if (counts[toRemove] == 1) {
                    required++;
                }
                left++;
                if (required == 0) {
                    minLen = Math.min(minLen, right - left + 1 - total);
                } else {
                    right++;
                }
            } else {
                int toAdd = knights[right] - 1;
                counts[toAdd]--;
                if (counts[toAdd] == 0) {
                    required--;
                }
                if (required == 0) {
                    minLen = Math.min(minLen, right - left + 1 - total);
                } else {
                    right++;
                }
            }
        }

        out.println(minLen == knights.length ? -1 : minLen);
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
