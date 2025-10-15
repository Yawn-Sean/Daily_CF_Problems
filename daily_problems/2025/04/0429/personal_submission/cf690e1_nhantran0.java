import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/690/E1">E1. Photographs (I)</a>
 * <p>Author: nhant
 * <p>2025-04-29 12:04:01 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/690/317693469">Apr/29/2025 12:26UTC+8, 1796 ms, 0 KB</a>
 **/
public class E1 {
  static IO io;
  static int[][] a;

  static int diff(int r1, int r2) {
    int d = 0;
    for (int j = 0, C = a[0].length; j < C; j++) {
      d += Math.abs(a[r1][j] - a[r2][j]);
    }
    return d;
  }
  
  private static void solve() {
    int h = io.ni(), w = io.ni();
    a = new int[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        a[i][j] = io.ni();
      }
    }
    int topDiff = diff(0, h - 1), midDiff = diff(h / 2 - 1, h / 2);
    io.println(topDiff < midDiff ? "YES" : "NO");
  }
  
  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.ni();
      while (tc-- > 0) {
        solve();
      }
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
