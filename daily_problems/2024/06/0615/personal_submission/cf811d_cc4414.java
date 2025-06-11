// Submission link: https://codeforces.com/contest/811/submission/265887219
import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        InputReader in;
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            for (int t = 0; t < testNumber; t++) {
                int n = in.nextInt();
                int m = in.nextInt();
                char[][] matrix = new char[n][m];
                for (int i = 0; i < n; i++) {
                    matrix[i] = in.next().toCharArray();
                }
                int[] finish = new int[2];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (matrix[i][j] == 'F') {
                            finish = new int[]{i, j};
                        }
                    }
                }
                int swapLR;
                int swapUD;
                int[] pos;
                if (m > 1 && matrix[0][1] != '*') {
                    pos = query("R");
                    if (pos[0] == finish[0] && pos[1] == finish[1]) {
                        return;
                    }
                    swapLR = pos[1];
                    if (swapLR == 1) {
                        pos = query("L");
                    }
                    while (n > 1 && matrix[1][pos[1]] == '*') {
                        pos = query(swapLR == 1 ? "R" : "L");
                        if (pos[0] == finish[0] && pos[1] == finish[1]) {
                            return;
                        }
                    }
                    pos = query("D");
                    if (pos[0] == finish[0] && pos[1] == finish[1]) {
                        return;
                    }
                    swapUD = pos[0];
                } else {
                    pos = query("D");
                    if (pos[0] == finish[0] && pos[1] == finish[1]) {
                        return;
                    }
                    swapUD = pos[0];
                    if (swapUD == 1) {
                        pos = query("U");
                    }
                    while (m > 1 && matrix[pos[0]][1] == '*') {
                        pos = query(swapUD == 1 ? "D" : "U");
                        if (pos[0] == finish[0] && pos[1] == finish[1]) {
                            return;
                        }
                    }
                    pos = query("R");
                    if (pos[0] == finish[0] && pos[1] == finish[1]) {
                        return;
                    }
                    swapLR = pos[1];
                }
                int[][] dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                ArrayDeque<int[]> deque = new ArrayDeque<>();
                int[][] dis = new int[n][m];
                int[][][] p = new int[n][m][2];
                boolean[][] vis = new boolean[n][m];
                deque.add(pos);
                vis[pos[0]][pos[1]] = true;
                while (!deque.isEmpty()) {
                    int[] first = deque.removeFirst();
                    for (int[] d : dxy) {
                        int x = first[0] + d[0];
                        int y = first[1] + d[1];
                        if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && matrix[x][y] != '*') {
                            dis[x][y] = dis[first[0]][first[1]] + 1;
                            p[x][y][0] = first[0];
                            p[x][y][1] = first[1];
                            deque.add(new int[]{x, y});
                            vis[x][y] = true;
                        }
                    }
                }
                StringBuilder sb = new StringBuilder();
                while (finish[0] != pos[0] || finish[1] != pos[1]) {
                    int i = p[finish[0]][finish[1]][0];
                    int j = p[finish[0]][finish[1]][1];
                    int dx = i - finish[0];
                    if (dx != 0) {
                        if (dx == 1) {
                            if (swapUD == 1) {
                                sb.append('U');
                            } else {
                                sb.append('D');
                            }
                        } else {
                            if (swapUD == 1) {
                                sb.append('D');
                            } else {
                                sb.append('U');
                            }
                        }
                    }
                    int dy = j - finish[1];
                    if (dy != 0) {
                        if (dy == 1) {
                            if (swapLR == 1) {
                                sb.append('L');
                            } else {
                                sb.append('R');
                            }
                        } else {
                            if (swapLR == 1) {
                                sb.append('R');
                            } else {
                                sb.append('L');
                            }
                        }
                    }
                    finish[0] = i;
                    finish[1] = j;
                }
                for (char c : sb.reverse().toString().toCharArray()) {
                    query(String.valueOf(c));
                }
            }
        }

        public int[] query(String s) {
            out.println(s);
            out.flush();
            return new int[]{in.nextInt() - 1, in.nextInt() - 1};
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
