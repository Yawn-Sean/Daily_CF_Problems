import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class DP1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "XX..\n" +
            "...O\n" +
            ".X..";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new DP1().run();
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

    static int MOD = (int) (1e9 + 7);

    void solve() {
        int n = is.ni();
        char[][] grid = is.nm(3, n);

        int[] circle = {-1, -1};
        outer: for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[j][i] == 'O') {
                    circle[0] = j;
                    circle[1] = i;
                    break outer;
                }
            }
        }

        long count = 0;
        List<int[]> validMoves = new ArrayList<>();
        if (circle[1] - 2 >= 0 && grid[circle[0]][circle[1] - 1] == '.' && grid[circle[0]][circle[1] - 2] == '.') {
            validMoves.add(new int[] {0, -1});
        }
        if (circle[1] + 2 < n && grid[circle[0]][circle[1] + 1] == '.' && grid[circle[0]][circle[1] + 2] == '.') {
            validMoves.add(new int[] {0, 1});
        }
        if (circle[0] == 2 && grid[0][circle[1]] == '.' && grid[1][circle[1]] == '.') {
            validMoves.add(new int[] {-1, 0});
        }
        if (circle[0] == 0 && grid[1][circle[1]] == '.' && grid[2][circle[1]] == '.') {
            validMoves.add(new int[] {1, 0});
        }
        int sign = 1;
        for (int len = 1; len <= validMoves.size(); len++) {
            for (int i = 0; i + len <= validMoves.size(); i++) {
                for (int j = i; j < i + len; j++) {
                    apply(grid, circle, validMoves.get(j), false);
                }
                count += sign * getCount(n, grid);
                count %= MOD;
                for (int j = i; j < i + len; j++) {
                    apply(grid, circle, validMoves.get(j), true);
                }
            }
            sign = -sign;
        }
        count %= MOD;
        if (count < 0) {
            count += MOD;
        }

        out.println(count);
    }

    private void apply(char[][] grid, int[] circle, int[] moves, boolean reverse) {
        int x = moves[0];
        int y = moves[1];
        if (x != 0) {
            if (!reverse) {
                grid[circle[0] + x][circle[1]] = 'X';
                grid[circle[0] + 2 * x][circle[1]] = 'X';
            } else {
                grid[circle[0] + x][circle[1]] = '.';
                grid[circle[0] + 2 * x][circle[1]] = '.';
            }
        }
        if (y != 0) {
            if (!reverse) {
                grid[circle[0]][circle[1] + y] = 'X';
                grid[circle[0]][circle[1] + 2 * y] = 'X';
            } else {
                grid[circle[0]][circle[1] + y] = '.';
                grid[circle[0]][circle[1] + 2 * y] = '.';
            }
        }
    }

    private long getCount(int n, char[][] grid) {
        long[][] dp = new long[8][n + 1];
        dp[7][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int shape = 0; shape < 8; shape++) {
                for (int prevShape : validPrevShapes(shape, grid, i - 1)) {
                    dp[shape][i] += dp[prevShape][i - 1];
                    dp[shape][i] %= MOD;
                }
            }
        }

        return dp[7][n];
    }

    private List<Integer> validPrevShapes(int shape, char[][] grid, int ind) {
        int curr = 0;
        for (int i = 0; i < 3; i++) {
            if (grid[i][ind] == 'O' || grid[i][ind] == 'X') {
                curr |= 1 << i;
            }
        }

        List<Integer> shapes = new ArrayList<>();

        if ((shape | curr) != shape) {
            return shapes;
        }
        shape -= curr;

        switch (shape) {
            case 0: {
                shapes.add(7);
                break;
            }
            case 1: {
                shapes.add(6);
                break;
            }
            case 2: {
                shapes.add(5);
                break;
            }
            case 3: {
                shapes.add(7);
                shapes.add(4);
                break;
            }
            case 4: {
                shapes.add(3);
                break;
            }
            case 5: {
                shapes.add(2);
                break;
            }
            case 6: {
                shapes.add(7);
                shapes.add(1);
                break;
            }
            case 7: {
                shapes.add(3);
                shapes.add(6);
                shapes.add(0);
                break;
            }
        }

        return shapes;
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

        private char[][] nm(int n, int m) {
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
