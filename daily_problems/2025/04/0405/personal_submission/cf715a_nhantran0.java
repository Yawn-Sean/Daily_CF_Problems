import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/715/A">A. Plus and Square Root</a>
 * <p>Author: nhant
 * <p>2025-04-05 22:42:54 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/715/314080431">Apr/05/2025 22:48UTC+8</a>
 **/
public class A {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    io.println(2);
    for (int i = 2; i <= n; i++) {
      io.println(((long) i + 1) * (i + 1) * i - (i - 1));
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
