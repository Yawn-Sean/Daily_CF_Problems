import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class DP {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
            "0 0 0";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new DP().run();
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
        int[] a = is.na(n);
        int[] suffix = new int[n + 1];
        suffix[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + a[i];
        }

        int[] dp = new int[n + 1];
        List<int[]>[] ranges = new List[n + 1];
        for (int i = n; i >= 0; i--) {
            ranges[i] = new ArrayList<>();
        }
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = Math.max(suffix[i], dp[i + 1] + a[i]);
            ranges[i] = new ArrayList<>(ranges[i + 1]);

            for (int j = i; j < n; j++) {
                int mexSum = (j - i + 1) * (j - i + 1);
                if (mexSum + dp[j + 1] > dp[i]) {
                    dp[i] = mexSum + dp[j + 1];
                    ranges[i] = new ArrayList<>(ranges[j + 1]);
                    ranges[i].add(new int[] {i, j});
                }
            }
        }

        List<int[]> operations = new ArrayList<>();
        for (int[] range : ranges[0]) {
            getOperations(a, range[0], range[1], operations, true);
        }

        out.println(dp[0] + " " + operations.size());
        for (int[] op : operations) {
            out.println((op[0] + 1) + " " + (op[1] + 1));
        }
    }

    private void getOperations(int[] a, int left, int right, List<int[]> operations, boolean lastStep) {
        for (int i = left; i <= right; i++) {
            if (a[i] != 0) {
                operations.add(new int[] {i, i});
                a[i] = 0;
            }
        }

        if (left == right) {
            operations.add(new int[] {left, left});
            a[left] = 1;
            return;
        }

        getOperations(a, left + 1, right, operations, true);
        if (left < right - 1) {
            getOperations(a, left, right - 1, operations, false);
        }
        if (lastStep) {
            operations.add(new int[] {left, right});
            for (int i = left; i <= right; i++) {
                a[i] = 1;
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
