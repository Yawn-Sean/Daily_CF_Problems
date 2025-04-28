import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1468/D">D. Firecrackers</a>
 * <p>Author: nhant
 * <p>2025-04-24 23:08:23 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/1468/317040936">Apr/24/2025 23:40UTC+8, 405 ms, 4300 KB</a>
 **/
public class D {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    int m = io.nextInt();
    int a = io.nextInt();
    int b = io.nextInt();
    int[] f = new int[m];
    for (int i = 0; i < m; i++) {
      f[i] = io.nextInt();
    }
    Arrays.sort(f);
    int res = 0;
    int d = a < b ? a : n + 1 - a;
    for (int i = m - 1, k = Math.abs(a - b) - 1; i >= 0 && k > 0; i--) {
      if (f[i] < d + k) { // firecracker explodes at time f[i] + 1
        res++;
        k--;
      }
    }
    io.println(res);
  }
  
  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.nextInt();
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
