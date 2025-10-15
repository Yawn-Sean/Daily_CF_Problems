import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/599/C">C. Day at the Beach</a>
 * <p>Author: nhant
 * <p>2025-05-03 15:34:26 +0800
 * https://codeforces.com/problemset/submission/599/318189918, O(nlog(n)) 311 ms, O(n) 1000 KB
 **/
public class C {
  static IO io;
  
  private static void solve() {
    int n = io.ni();
    int[] h = new int[n];
    Integer[] ord = new Integer[n];
    for (int i = 0; i < n; i++) {
      h[i] = io.ni();
      ord[i] = i;
    }
    Arrays.sort(ord, (i, j) -> h[i] - h[j]);
    int res = 0;
    for (int i = 0, last = -1; i < n; i++) {
      int l = Math.min(i, ord[i]), r = Math.max(i, ord[i]);
      if (last < l) {
        res++;
      }
      last = Math.max(last, r);
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
