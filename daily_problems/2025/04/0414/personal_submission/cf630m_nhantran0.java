import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/630/M">M. Turn</a>
 * <p>Author: nhant
 * <p>2025-04-14 21:48:02 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/630/315582908">Apr/14/2025 22:12UTC+8</a>
 **/
public class M {
  static IO io;
  
  private static void solve() {
    int A = 360;
    long x = io.nextLong();
    x %= A;
    if (x < 0) x += A;
    x = (x <= 45 || x >= A - 45 ? 0 : x);
    io.println((x + 44) / 90);
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
