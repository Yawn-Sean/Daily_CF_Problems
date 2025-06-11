import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/847/C">C. Sum of Nestings</a>
 * <p>Author: nhant
 * <p>2025-04-23 00:24:44 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/847/316713841">Apr/23/2025 00:35UTC+8</a>
 **/
public class C {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    long k = io.nextLong();
    if (k > ((long) n - 1) * n / 2) io.println("Impossible");
    else {
      StringBuilder b = new StringBuilder(2 * n);
      for (int i = 0, n2 = n * 2, bal = 0; i < n2; i++) {
        if (k >= bal || bal == 0) {
          b.append('(');
          k -= bal;
          bal++;
        } else {
          b.append(')');
          bal--;
        }
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
