import java.io.*;
import java.util.*;

public class LIS1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "6 3\n" +
            "1 14.284235\n" +
            "2 17.921382\n" +
            "1 20.328172\n" +
            "3 20.842331\n" +
            "1 25.790145\n" +
            "1 27.204125";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new LIS1().run();
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

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = is.ni();
            is.nd();
        }

        replant(n, nums);
    }

    private void replant(int n, int[] nums) {
        List<Integer> lis = new ArrayList<>();

        for (int num : nums) {
            int ind = Collections.binarySearch(lis, num);
            if (ind < 0) {
                ind = ~ind;
            } else {
                while (ind < lis.size() && lis.get(ind) == num) {
                    ind++;
                }
            }
            if (ind == lis.size()) {
                lis.add(num);
            } else {
                lis.set(ind, num);
            }
        }

        out.println(n - lis.size());
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

        double nd() {
            return Double.parseDouble(ns());
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
