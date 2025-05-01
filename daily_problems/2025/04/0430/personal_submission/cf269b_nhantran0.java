import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/269/B">B. Greenhouse Effect</a>
 * <p>Author: nhant
 * <p>2025-05-01 00:34:05 +0800
 * https://codeforces.com/problemset/submission/269/317864604, 622 ms, 1400 KB
 **/
public class B {
  static IO io;
  
  private static void solve() {
    int n = io.ni(), m = io.ni();
    int[] s = new int[n], l = new int[n];
    int lmx = 1;
    for (int i = 0; i < n; i++) {
      s[i] = io.ni();
      double x = io.nd();
      l[i] = 1;
      for (int j = 0; j < i; j++) {
        if (s[j] <= s[i] && l[j] + 1 > l[i]) {
          l[i] = l[j] + 1;
          if (lmx < l[i]) {
            lmx = l[i];
          }
        }
      }
    }
    io.println(n - lmx);
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

    public double nd() {
      return Double.parseDouble(next());
    }
  }
}
