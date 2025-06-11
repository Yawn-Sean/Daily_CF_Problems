import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/317/A">A. Perfect Pair</a>
 * <p>Author: nhant
 * <p>2025-04-19 16:42:30 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/317/316197815">Apr/19/2025 16:55UTC+8</a>
 **/
public class A {
  static IO io;
  
  private static void solve() {
    long x = io.nextLong();
    long y = io.nextLong();
    long m = io.nextLong();
    long res = 0;
    if (Math.max(x, y) < m) {
      if (x <= 0 && y <= 0) {
        res = -1;
      } else {
        if (y <= 0) {
          long z = x;
          x = y;
          y = z;
        }
        if (x <= 0) {
          res += (-x + y - 1) / y;
          x += res * y;
        }
        while (x < m && y < m) {
          if (x <= y) {
            x += y;
          } else {
            y += x;
          }
          res++;
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
  
    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
