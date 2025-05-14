import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/294/B">B. Shaass and Bookshelf</a>
 * <p>Author: nhant
 * <p>2025-05-14 22:56:03 +0800
 * https://codeforces.com/problemset/submission/294/319664404
 **/
public class B {
  static IO io;
  
  private static void solve() {
    int n = io.ni();
    int[] t = new int[n], w = new int[n];
    int tsum = 0;
    for (int i = 0; i < n; i++) {
      t[i] = io.ni();
      w[i] = io.ni();
      tsum += t[i];
    }
    boolean[][] d = new boolean[tsum + 1][tsum + 1];
    d[tsum][0] = true;
    int res = tsum;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= tsum; j++) {
        for (int k = Math.min(tsum, j - t[i] - w[i]); k >= 0; k--) {
          if (d[j][k]) {
            d[j - t[i]][k + w[i]] = true;
            res = Math.min(res, j - t[i]);
          }
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
