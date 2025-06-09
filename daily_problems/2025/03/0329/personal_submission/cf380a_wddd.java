import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Simulation {

    FastReader is;
    PrintWriter out;
    String INPUT = "6\n" +
            "1 1\n" +
            "1 2\n" +
            "2 2 1\n" +
            "1 3\n" +
            "2 5 2\n" +
            "1 4\n" +
            "16\n" +
            "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Simulation().run();
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
        int m = is.ni();
        long ind = 0;
        TreeSet<Range> ranges = new TreeSet<Range>();

        for (int i = 0; i < m; i++) {
            int type = is.ni();
            int[] val;
            if (type == 1) {
                val = new int[] {is.ni()};
            } else {
                val = new int[] {is.ni(), is.ni()};
            }
            Range range = new Range(ind, type, val);
            ranges.add(range);
            ind += type == 1 ? 1 : (long) val[0] * val[1];
        }

        int n = is.ni();
        for (int i = 0; i < n; i++) {
            long target = is.nl() - 1;
            int val = getValue(ranges, target);
            out.print(val + " ");
        }
        out.println();
    }

    private int getValue(TreeSet<Range> ranges, long ind) {
        Range range = ranges.floor(new Range(ind, 0, null));
        if (range.type == 1) {
            return range.val[0];
        } else {
            return getValue(ranges, (ind - range.ind) % range.val[0]);
        }
    }

    static class Range implements Comparable<Range> {
        long ind;
        int type;
        int[] val;

        public Range(long ind, int type, int[] val) {
            this.ind = ind;
            this.type = type;
            this.val = val;
        }

        @Override
        public int compareTo(Range that) {
            return Long.compare(this.ind, that.ind);
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
