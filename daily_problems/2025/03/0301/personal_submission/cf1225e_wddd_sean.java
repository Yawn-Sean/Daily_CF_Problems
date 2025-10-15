import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DP4 {

    FastReader is;
    PrintWriter out;
//    String INPUT = "1 2\n" +
//            "..\n";
//    String INPUT = "2 3\n" +
//            "...\n" +
//            ".R.\n";
//    String INPUT = "1 3\n" +
//            ".R.";
    String INPUT = "4 4\n" +
            "...R\n" +
            ".RR.\n" +
            ".R..\n" +
            "R...\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new DP4().run();
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
        int r = is.ni();
        int c = is.ni();
        char[][] grid = is.nm(r, c);
        push(r, c, grid);
    }

    private void push(int r, int c, char[][] grid) {
        if (grid[r - 1][c - 1] == 'R') {
            out.println(0);
            return;
        }
        if (r == 1 && c == 1) {
            out.println(1);
            return;
        }

        int mod = (int) (1e9 + 7);

        int[][] rsR = new int[r][c];
        int[][] rsD = new int[r][c];
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i + 1 < r) {
                    rsR[i][j] = rsR[i + 1][j];
                }
                if (j + 1 < c) {
                    rsD[i][j] = rsD[i][j + 1];
                }
                if (grid[i][j] == 'R') {
                    rsR[i][j]++;
                    rsD[i][j]++;
                }
            }
        }

        int[][] dpR = new int[r][c];
        int[][] dpD = new int[r][c];
        int[][] prefixR = new int[r][c];
        int[][] prefixD = new int[r][c];
        for (int i = r - 2; i >= 0; i--) {
            if (grid[i][c - 1] == 'R') {
                for (int j = i; j >= 0; j--) {
                    prefixR[j][c - 1] = prefixR[j + 1][c - 1];
                }
                break;
            }
            dpR[i][c - 1] = 1;
            dpD[i][c - 1] = 1;
            prefixR[i][c - 1] = dpR[i][c - 1] + prefixR[i + 1][c - 1];
        }
        for (int j = c - 2; j >= 0; j--) {
            if (grid[r - 1][j] == 'R') {
                for (int i = j; i >= 0; i--) {
                    prefixD[r - 1][i] = prefixD[r - 1][i + 1];
                }
                break;
            }
            dpR[r - 1][j] = 1;
            dpD[r - 1][j] = 1;
            prefixD[r - 1][j] = dpD[r - 1][j] + prefixD[r - 1][j + 1];
        }
        for (int i = r - 2; i >= 0; i--) {
            for (int j = c - 2; j >= 0; j--) {
                if (grid[i][j] != 'R') {
                    dpD[i][j] = (dpD[i + 1][j] + dpR[i][j + 1]) % mod;
                    dpR[i][j] = dpD[i][j];
                } else {
                    int m = r - i - rsR[i][j];
                    dpD[i][j] += (prefixR[i][j + 1] - (i + m == r ? 0 : prefixR[i + m][j + 1])) % mod;
                    if (dpD[i][j] < 0) {
                        dpD[i][j] += mod;
                    }

                    m = c - j - rsD[i][j];
                    dpR[i][j] += (prefixD[i + 1][j] - (j + m == c ? 0 : prefixD[i + 1][j + m])) % mod;
                    if (dpR[i][j] < 0) {
                        dpR[i][j] += mod;
                    }
                }
                prefixR[i][j] = (dpR[i][j] + prefixR[i + 1][j]) % mod;
                prefixD[i][j] = (dpD[i][j] + prefixD[i][j + 1]) % mod;
            }
        }

        if (grid[0][0] != 'R') {
            out.println(dpR[0][0]);
        } else {
            out.println(dpR[0][0] + dpD[0][0]);
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        char[] ns(int n) {
            try {
                char[] buf = new char[n];
                for (int i = 0; i < n; i++) {
                    char c = (char) br.read();
                    while (isSpaceChar(c)) {
                        c = (char) br.read();
                    }
                    buf[i] = c;
                }
                return buf;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        int ni() {
            return Integer.parseInt(ns());
        }

        char[][] nm(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = ns(m);
            }
            return map;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
