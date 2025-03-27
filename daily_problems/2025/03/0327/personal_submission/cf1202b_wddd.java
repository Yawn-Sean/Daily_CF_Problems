import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BruteForce2 {

    FastReader is;
    PrintWriter out;
    String INPUT = "0840\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BruteForce2().run();
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
        int[] minMisses = new int[10000];
        Arrays.fill(minMisses, -1);
        for (int i = 0; i < 10; i++) {
            for (int j = i; j < 10; j++) {
                for (int prev = 0; prev < 10; prev++) {
                    for (int curr = 0; curr < 10; curr++) {
                        int minMiss = getMinMiss(i, j, curr, prev);
                        minMisses[getKey(i, j, curr, prev)] = minMiss;
                    }
                }
            }
        }

        String s = is.ns();
        int[][] result = new int[10][10];

        for (int i = 0; i < 10; i++) {
            loopJ: for (int j = 0; j < 10; j++) {
                if (j < i) {
                    result[i][j] = result[j][i];
                } else {
                    int prev = 0;
                    int total = 0;
                    for (int k = 1; k < s.length(); k++) {
                        int curr = s.charAt(k) - '0';
                        int minMiss = minMisses[getKey(i, j, curr, prev)]; //tupleToMinMiss.get(getKey(i, j, curr, prev));
                        if (minMiss == -1) {
                            result[i][j] = -1;
                            out.print(result[i][j] + " ");
                            continue loopJ;
                        } else {
                            total += minMiss - 1;
                        }
                        prev = curr;
                    }
                    result[i][j] = total;
                }
                out.print(result[i][j] + " ");
            }
            out.println();
        }
    }

    private int getKey(int i, int j, int prev, int curr) {
        return i * 1000 + j * 100 + prev * 10 + curr;
    }

    private int getMinMiss(int x, int y, int curr, int prev) {
        int min = Integer.MAX_VALUE;
        int diff = curr - prev;
        if (diff == 0 && (x == 0 || y == 0)) {
            return 1;
        }
        for (int i = 0; i < 10; i++) {
            if (diff >= x || diff >= y) {
                int xt = 0;
                do {
                    int remaining = diff - x * xt;
                    if (remaining >= 0 && y != 0 && remaining % y == 0) {
                        min = Math.min(min, xt + remaining / y);
                    }
                    xt++;
                } while (x * xt <= diff && x > 0);
            }
            diff += 10;
        }

        return min == Integer.MAX_VALUE ? -1 : min;
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
