import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/12/E">E. Start of the season</a>
 * <p>Author: nhant
 * <p>2025-05-10 12:40:34 +0800
 * https://codeforces.com/problemset/submission/12/319011974, 748 ms
 * https://codeforces.com/problemset/submission/12/319014061, 530 ms (StringBuilder with capacity)
 **/
public class E {
  static IO io;
  
  private static void solve() {
    int n = io.ni();
    int[][] g = new int[n][n];
    int[] rowSum = new int[n];
    for (int r = 0; r < n - 1; r++) {
      for (int c = r + 1; c < n - 1; c++) {
        if (r < n - 1 && c < n - 1) {
          int x = (r + c) % (n - 1);
          g[r][c] = g[c][r] = x;
          rowSum[r] += x;
          rowSum[c] += x;
        }
      }
      if (r < n - 1 && n - 1 - r < n - 1) {
        int x = n - 1;
        g[r][n - 1 - r] = g[n - 1 - r][r] = x;
        rowSum[r] += x;
      }
    }
    int m = (n - 1) * n / 2;
    for (int r = 0; r < n - 1; r++) {
      g[r][n - 1] = g[n - 1][r] = m - rowSum[r];
    }
    for (int[] row : g) {
      StringBuilder b = new StringBuilder(n * 2);
      for (int x : row) {
        b.append(x).append(' ');
      }
      io.println(b);
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
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
