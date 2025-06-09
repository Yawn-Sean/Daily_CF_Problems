import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
            "aa\n" +
            "jj\n" +
            "aa\n";

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
        String[] nums = new String[n];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = is.ns();
        }
        int[][] stats = new int[10][2];
        for (String num : nums) {
            int base = 1;
            for (int i = num.length() - 1; i >= 0; i--) {
                int digit = num.charAt(i) - 'a';
                stats[digit][0] += base;
                base *= 10;
                if (i == 0) {
                    stats[digit][1] = 1;
                }
            }
        }
        Arrays.sort(stats, (x, y) -> {
            if (x[0] != y[0]) {
                return Integer.compare(y[0], x[0]);
            } else {
                return Integer.compare(x[1], y[1]);
            }
        });
        
        long sum = 0;
        boolean zero = false;
        int digit = 1;
        for (int i = 0; i < stats.length; i++) {
            if (stats[i][1] == 0 && !zero) {
                zero = true;
                continue;
            }

            sum += (long) stats[i][0] * digit;
            digit++;
        }
        out.println(sum);
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
