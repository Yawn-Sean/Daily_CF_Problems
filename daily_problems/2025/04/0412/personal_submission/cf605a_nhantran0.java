import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/605/A">A. Sorting Railway Cars</a>
 * <p>Author: nhant
 * <p>2025-04-12 23:24:41 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/605/315191134">Apr/13/2025 01:21UTC+8</a>
 **/
public class A {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    boolean[] saw = new boolean[n];
    int[] len = new int[n];
    int res = n - 1;
    for (int i = 0; i < n; i++) {
      int p = io.nextInt();
      p--;
      saw[p] = true;
      len[p] = 1;
      if (p > 0 && saw[p - 1]) {
        len[p] = len[p - 1] + 1;
      }
      res = Math.min(res, n - len[p]);
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
