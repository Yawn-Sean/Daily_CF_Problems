import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Naive3 {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "8\n" +
            "5 2 1 0 3 0 4 0\n" +
            "2\n" +
            "1 2\n" +
            "5\n" +
            "1 0 2 114514 0\n" +
            "8\n" +
            "0 1 2 0 1 2 0 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Naive3().run();
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
            int n = is.ni();
            int[] a = is.na(n);
            Map<Integer, Integer> map = new HashMap<>();
            for (int x : a) {
                map.put(x, map.getOrDefault(x, 0) + 1);
            }
            int mex = 0;
            for (int j = 0; ; j++) {
                if (!map.containsKey(j)) {
                    mex = j;
                    break;
                }
            }
            Map<Integer, Long> cache = new HashMap<>();
            long min = minSum(mex, map, cache);
            out.println(min);
        }
    }

    private long minSum(int mex, Map<Integer, Integer> map, Map<Integer, Long> cache) {
        if (mex <= 0 || map.isEmpty()) {
            return 0;
        }
        if (cache.containsKey(mex)) {
            return cache.get(mex);
        }

        long result = Long.MAX_VALUE / 2;
        for (int toRemove = 0; toRemove < mex; toRemove++) {
            int count = map.get(toRemove);
            if ((long) (count - 1) * mex + toRemove < result) {
                map.remove(toRemove);
                result = Math.min(result, (long) (count - 1) * mex + toRemove + minSum(toRemove, map, cache));
                map.put(toRemove, count);
            }
        }

        cache.put(mex, result);
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
