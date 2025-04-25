import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/793/B">B. Igor and his way to work</a>
 * <p>Author: nhant
 * <p>2025-04-25 18:02:44 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/793/317158772">Apr/25/2025 18:30UTC+8, 640 ms, 41000 KB</a>
 **/
public class B {
  static IO io;

  private static void solve() {
    final int[][] dirs = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    final int MAX_TURN = 4;
    int n = io.nextInt();
    int m = io.nextInt();
    char[][] s = new char[n][];
    int[][][] turn = new int[n][m][4];
    int sr = -1, sc = -1, tr = -1, tc = -1;
    for (int i = 0; i < n; i++) {
      s[i] = io.next().toCharArray();
      for (int j = 0; j < m; j++) {
        Arrays.fill(turn[i][j], MAX_TURN);
        if (s[i][j] == 'S') {
          sr = i;
          sc = j;
        } else if (s[i][j] == 'T') {
          tr = i;
          tc = j;
        }
      }
    }
    Queue<int[]> q = new LinkedList<>();
    for (int i = 0; i < 4; i++) {
      q.add(new int[]{sr, sc, i});
      turn[sr][sc][i] = 0;
    }
    boolean yes = false;
    while (!q.isEmpty()) {
      int[] el = q.poll();
      int r = el[0], c = el[1], d = el[2];
      if (r == tr && c == tc) {
        yes = true;
        break;
      }
      if (turn[r][c][d] < 2) {
        for (int i = 0; i < 4; i++) {
          if (i == d) continue;
          if (turn[r][c][d] + 1 < turn[r][c][i]) {
            turn[r][c][i] = turn[r][c][d] + 1;
            q.add(new int[]{r, c, i});
          }
        }
      }
      int nr = r + dirs[d][0], nc = c + dirs[d][1];
      if (0 <= nr && nr < n && 0 <= nc && nc < m && s[nr][nc] != '*' && turn[r][c][d] < turn[nr][nc][d]) {
        turn[nr][nc][d] = turn[r][c][d];
        q.add(new int[]{nr, nc, d});
      }
    }
    io.println(yes ? "YES" : "NO");
  }

  public static void main(String[] args) {
    try {
      io = new IO();
      solve();
    } finally {
      io.close();
    }
  }

  static class IO extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;

    public IO() {
      this(System.in, System.out);
    }

    public IO(InputStream i, OutputStream o) {
      super(o);
      r = new BufferedReader(new InputStreamReader(i), 1 << 15);
    }

    public String next() {
      try {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
        return st.nextToken();
      } catch (Exception e) {
      }
      return null;
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
