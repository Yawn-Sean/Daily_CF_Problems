import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/contest/1090/problem/E">E. Horseback Riding</a>
 * <p>Author: nhant
 * <p>2025-04-05 23:01:11 +0800
 * <p>Submission: <a href=""></a>
 **/
public class E {
  static IO io;

  static final int[][] steps = new int[][]{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

  private static String numToName(int r, int c) {
    return "" + (char) ('a' + c) + (char) ('1' + r);
  }

  private static void solve() {
    final int L = 8;
    boolean[][] b = new boolean[L][L];
    int k = io.nextInt();
    for (int i = 0; i < k; i++) {
      String s = io.next();
      b[s.charAt(1) - '1'][s.charAt(0) - 'a'] = true;
    }
    boolean[][] visited = new boolean[L][L];
    List<String> moves = new ArrayList<>();
    for (int i = 0; i < k; i++) {
      int r = i / L, c = i % L;
      if (!b[r][c]) {
        Queue<Cell> q = new ArrayDeque<>();
        for (boolean[] v : visited) Arrays.fill(v, false);
        q.add(new Cell(r, c, null));
        visited[r][c] = true;
        Cell end = null;
        while (!q.isEmpty()) {
          Cell u = q.poll();
          if (b[u.r][u.c] && u.r * 8 + u.c >= k) {
            end = u;
            break;
          }
          for (int[] step : steps) {
            int nr = u.r + step[0], nc = u.c + step[1];
            if (0 <= nr && nr < L && 0 <= nc && nc < L && !visited[nr][nc]) {
              q.add(new Cell(nr, nc, u));
              visited[nr][nc] = true;
            }
          }
        }
        List<Cell> path = new ArrayList<>();
        while (end != null) {
          path.add(end);
          end = end.prev;
        }
        for (int pLen = path.size(), j = pLen - 2; j >= 0; j--) {
          Cell cur = path.get(j);
          if (b[cur.r][cur.c]) { // has horse
            for (int pi = j; pi < pLen - 1; pi++) {
              Cell fr = path.get(pi);
              Cell to = path.get(pi + 1);
              if (b[to.r][to.c]) break;
              moves.add(numToName(fr.r, fr.c) + "-" + numToName(to.r, to.c));
              b[fr.r][fr.c] = false;
              b[to.r][to.c] = true;
            }
          }
        }
      }
    }
    io.println(moves.size());
    for (String s : moves) {
      io.println(s);
    }
  }

  private static class Cell {
    int r, c;
    Cell prev;

    public Cell(int r, int c, Cell prev) {
      this.r = r;
      this.c = c;
      this.prev = prev;
    }

    @Override
    public String toString() {
      return "Cell{" +
          "r=" + r +
          ", c=" + c +
          '}';
    }
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
