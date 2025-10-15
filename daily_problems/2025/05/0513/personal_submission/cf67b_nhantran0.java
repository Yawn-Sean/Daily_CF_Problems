import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/67/B">B. Restoration of the Permutation</a>
 * <p>Author: nhant
 * <p>2025-05-13 15:16:21 +0800
 * https://codeforces.com/problemset/submission/67/319475034, O(N^2)
 **/
public class B {
  static IO io;
  
  private static void solve() {
    int n = io.ni(), k = io.ni();
    int[] b = new int[n], a = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = io.ni();
    }
    for (int i = n - 1; i >= 0; i--) {
      int j = i;
      while (b[i] > 0 && j + 1 < n) {
        j++;
        if (a[j] >= i + 1 + k) {
          b[i]--;
        }
        a[j - 1] = a[j];
      }
      a[j] = i + 1;
    }
    for (int v : a) {
      io.printf("%d ", v);
    }
    io.println();
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
