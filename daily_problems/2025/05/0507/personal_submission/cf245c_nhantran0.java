import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/245/C">C. Game with Coins</a>
 * <p>Author: nhant
 * <p>2025-05-07 23:39:51 +0800
 * https://codeforces.com/problemset/submission/245/318750190, O(N)
 **/
public class C {
  static IO io;
  
  private static void solve() {
    int n = io.ni();
    int[] a = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      a[i] = io.ni();
    }
    int res = 0;
    for (int i = (n - 1) / 2 * 2; i > 0; i -= 2) {
      int d = Math.max(a[i], a[i + 1]);
      if (i == 2) {
        d = Math.max(d, a[1]);
      }
      res += d;
      a[i / 2] = Math.max(0, a[i / 2] - d);
      a[i] = a[i + 1] = 0;
    }
    for (int x : a) {
      if (x > 0) {
        io.println(-1);
        return;
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
