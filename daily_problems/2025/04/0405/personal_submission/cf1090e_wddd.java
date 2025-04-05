import java.io.*;
import java.util.*;

public class BFS1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "2\n" +
            "a2\n" +
            "a5\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BFS1().run();
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
        boolean[][] grid = new boolean[8][8];
        for (int i = 0; i < k; i++) {
            String p = is.ns();
            grid[p.charAt(1) - '1'][p.charAt(0) - 'a'] = true;
        }

        jump(k, grid);
    }

    static int[][] DIRS = new int[][] {
            {-2, 1},
            {-1, 2},
            {1, 2},
            {2, 1},
            {2, -1},
            {1, -2},
            {-1, -2},
            {-2, -1},
    };

    private void jump(int k, boolean[][] grid) {
        int done = 0;
        List<int[]> moves = new ArrayList<>();
        outer: for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (done == k) {
                    break outer;
                }
                if (!grid[i][j]) {
                    move(grid, i, j, moves);
                }
                done++;
            }
        }
        out.println(moves.size());
        for (int[] move : moves) {
            out.println((char) (move[1] + 'a') + "" + (char) (move[0] + '1')
                    + "-" + (char) (move[3] + 'a') + "" + (char) (move[2] + '1'));
        }
    }

    private void move(boolean[][] grid, int x, int y, List<int[]> moves) {
        Queue<Move> queue = new ArrayDeque<>();
        queue.add(new Move(new int[] {x, y}));
        boolean[][] visited = new boolean[8][8];
        visited[x][y] = true;

        while (true) {
            Move move = queue.poll();
            int[] curr = move.curr;
            if (grid[curr[0]][curr[1]] && (curr[0] > x || curr[0] == x && curr[1] > y)) {
                List<int[]> path = move.path;

                Stack<int[]> stack = new Stack<>();
                for (int i = path.size() - 1; i >= 0; i--) {
                    int[] prev = path.get(i);
                    if (grid[prev[0]][prev[1]]) {
                        stack.push(new int[] {curr[0], curr[1], prev[0], prev[1]});
                    } else {
                        moves.add(new int[] {curr[0], curr[1], prev[0], prev[1]});
                    }

                    if (grid[curr[0]][curr[1]]) {
                        grid[curr[0]][curr[1]] = false;
                    }

                    curr = prev;
                }

                while (!stack.isEmpty()) {
                    int[] pos = stack.pop();
                    moves.add(pos);
                    grid[pos[2]][pos[3]] = true;
                }
                grid[x][y] = true;

                break;
            }

            for (int[] dir : DIRS) {
                int nx = curr[0] + dir[0];
                int ny = curr[1] + dir[1];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                Move next = new Move(new int[] {nx, ny});
                next.path.addAll(move.path);
                next.path.add(curr);
                queue.add(next);
            }
        }
    }

    static class Move {
        int[] curr;
        List<int[]> path;

        public Move(int[] curr) {
            this.curr = curr;
            this.path = new ArrayList<>();
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
