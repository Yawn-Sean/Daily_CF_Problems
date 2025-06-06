import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BinarySearch {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "garage for sa-le\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BinarySearch().run();
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
        int k = is.ni();
        String s = is.nextLine();
        String[] words = s.split("[\s\\-]");

        int left = 0;
        int right = s.length() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (validMin(words, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        out.println(left);
    }

    private boolean validMin(String[] words, int k, int min) {
        int len = 0;
        for (int i = 0; i < words.length; i++) {
            int curr = words[i].length() + (i != words.length - 1 ? 1 : 0);
            if (curr > min) {
                return false;
            }

            if (len + curr > min) {
                len = curr;
                k--;
            } else {
                len += curr;
            }
        }

        return k > 0 || k == 0 && len == 0;
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

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
