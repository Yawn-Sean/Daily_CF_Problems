import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/375/B">B. Maximum Submatrix 2</a>
 * <p>Author: nhant
 * <p>2025-05-02 14:34:57 +0800
 * https://codeforces.com/contest/375/submission/318075912, 1703 ms, 254500 KB, slow
 *
 **/
public class B {
  static IO io;

  private static void solve() {
    int n = io.ni(), m = io.ni();
    int[][] end = new int[n][m];
    for (int i = 0; i < n; i++) {
      char[] s = io.next().toCharArray();
      for (int j = m - 1; j >= 0; j--) {
        if (s[j] == '0') {
          end[i][j] = -1;
        } else {
          end[i][j] = j == m - 1 || s[j + 1] == '0' ? j : end[i][j + 1];
        }
      }
    }
    int res = 0;
    int[] dif = new int[m + 1];
    for (int c = 0; c < m; c++) {
      Arrays.fill(dif, 0);
      for (int r = 0; r < n; r++) {
        if (end[r][c] == -1) {
          dif[c]--;
        } else {
          dif[end[r][c] + 1]--;
        }
      }
      int h = n;
      for (int i = c; i <= m && h > 0; i++) {
        h += dif[i];
        res = Math.max(res, h * (i - c + 1));
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
