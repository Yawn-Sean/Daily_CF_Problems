import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/89/A">A. Robbery</a>
 * <p>Author: nhant
 * <p>2025-05-06 07:34:01 +0800
 * https://codeforces.com/problemset/submission/89/318561321
 **/
public class A {
  static IO io;
  
  private static void solve() {
    int n = io.ni(), m = io.ni(), k = io.ni();
    int minOdd = (int)1e5;
    for (int i = 1; i <= n; i++) {
      int x = io.ni();
      if (i % 2 == 1) {
        minOdd = Math.min(minOdd, x);
      }
    }
    long res = 0;
    if (n % 2 == 1) {
      if (n == 1) {
        res = Math.min((long) m * k, minOdd);
      } else {
        res = Math.min((long) m / ((n + 1) / 2) * k, minOdd);
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
