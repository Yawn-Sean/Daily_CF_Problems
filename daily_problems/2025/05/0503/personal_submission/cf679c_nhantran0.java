import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/679/C">C. Bear and Square Grid</a>
 * <p>Author: nhant
 * <p>2025-05-04 06:41:17 +0800
 * https://codeforces.com/problemset/submission/679/318280459, 1749 ms, 19600 KB
 **/
public class CArrayBitSet {
  static final int[][] dirs = new int[][]{{-1,0},{0,1},{1,0},{0,-1}};
  static IO io;
  static int n, k, comp;
  static boolean[][] g, visited;
  static int[][] cc;

  static int dfs(int r, int c) {
    visited[r][c] = true;
    cc[r][c] = comp;
    int cnt = 1;
    for (int[] dir : dirs) {
      int nr = r + dir[0], nc = c + dir[1];
      if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && g[nr][nc] && !visited[nr][nc]) {
        cnt += dfs(nr, nc);
      }
    }
    return cnt;
  }

  private static void solve() {
    n = io.ni();
    k = io.ni();
    comp = 0;
    g = new boolean[n + 2][n + 2];
    visited = new boolean[n + 2][n + 2];
    cc = new int[n + 2][n + 2];
    for (int i = 1; i <= n; i++) {
      char[] s = io.next().toCharArray();
      for (int j = 1; j <= n; j++) {
        g[i][j] = s[j - 1] == '.';
      }
    }
    List<Integer> ccCnt = new ArrayList<>();
    ccCnt.add(0);
    for (int r = 1; r <= n; r++) {
      for (int c = 1; c <= n; c++) {
        if (g[r][c] && !visited[r][c]) {
          comp++;
          ccCnt.add(dfs(r, c));
        }
      }
    }

    int k2 = k * k;
    int[] inCcCnt = new int[comp + 1];
    BitSet outCcUsed = new BitSet(comp + 1);
    int res = 0;

    for (int i = k; i <= n; i++) {

      Arrays.fill(inCcCnt, 0);

      for (int j = 1; j <= n; j++) {

        for (int x = 0; x < k; x++) {
          if (cc[i - x][j] != 0) {
            inCcCnt[cc[i - x][j]]++;
          }
          if (j > k && cc[i - x][j - k] != 0) {
            inCcCnt[cc[i - x][j - k]]--;
          }
        }

        if (j >= k) {
          outCcUsed.clear();

          int cnt = k2;

          for (int x = 0; x < k; x++) {
            int tc = cc[i - k][j - x];
            if (tc != 0  && !outCcUsed.get(tc)) {
              outCcUsed.set(tc);
              cnt += ccCnt.get(tc) - inCcCnt[tc];
            }
            int rc = cc[i - x][j + 1];
            if (rc != 0 && !outCcUsed.get(rc)) {
              outCcUsed.set(rc);
              cnt += ccCnt.get(rc) - inCcCnt[rc];
            }
            int bc = cc[i + 1][j - x];
            if (bc != 0 && !outCcUsed.get(bc)) {
              outCcUsed.set(bc);
              cnt += ccCnt.get(bc) - inCcCnt[bc];
            }
            int lc = cc[i - x][j - k];
            if (lc != 0 && !outCcUsed.get(lc)) {
              outCcUsed.set(lc);
              cnt += ccCnt.get(lc) - inCcCnt[lc];
            }
          }
          res = Math.max(res, cnt);
        }
      }
    }
    io.println(res);
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

    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
