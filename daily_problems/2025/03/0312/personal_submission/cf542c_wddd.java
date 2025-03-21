import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Graph {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
        "2 3 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Graph().run();
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
        int[] fs = new int[n];
        int[] inDegrees = new int[n];
        for (int i = 0; i < n; i++) {
            fs[i] = is.ni() - 1;
            if (fs[i] != i) {
                inDegrees[fs[i]]++;
            }
        }

        int[] onStack = new int[n];
        Arrays.fill(onStack, -1);

        long cycleLcm = 1;
        long maxToCycle = 0;
        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == 0) {
                int[] cycle = cycleDfs(fs, i, onStack);
                cycleLcm = lcm(cycleLcm, cycle[0]);
                maxToCycle = Math.max(maxToCycle, cycle[1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (onStack[i] == -1) {
                int[] cycle = cycleDfs(fs, i, onStack);
                cycleLcm = lcm(cycleLcm, cycle[0]);
            }
        }

        out.println(maxToCycle == 0 ? cycleLcm : cycleLcm * Math.ceilDiv(maxToCycle, cycleLcm));
    }

    private int[] cycleDfs(int[] adjs, int v, int[] onStack) {
        onStack[v]++;

        int nv = adjs[v];
        if (nv == v) {
            int len = onStack[v];
            onStack[v] = -1;
            return new int[] {1, len};
        } else {
            int[] result;
            
            if (onStack[nv] == -1) {
                onStack[nv] = onStack[v];
                result = cycleDfs(adjs, nv, onStack);
            } else {
                result = new int[] {onStack[v] - onStack[nv] + 1, onStack[nv]};
            }

            onStack[v] = -1;
            return result;
        }
    }

    public static long gcd(long a, long b) {
        return b == 0 ? Math.abs(a) : gcd(b, a % b);
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
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
