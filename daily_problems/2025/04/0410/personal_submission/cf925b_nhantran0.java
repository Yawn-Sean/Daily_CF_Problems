import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/925/B">B. Resource Distribution</a>
 * <p>Author: nhant
 * <p>2025-04-11 04:42:17 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/925/314939553">Apr/11/2025 05:34UTC+8</a>
 **/
public class B {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    int x1 = io.nextInt();
    int x2 = io.nextInt();
    int[] c = new int[n];
    int[] k1Min = new int[n], k2Min = new int[n];
    Integer[] ord = new Integer[n];
    for (int i = 0; i < n; i++) {
      c[i] = io.nextInt();
      k1Min[i] = (x1 + c[i] - 1) / c[i];
      k2Min[i] = (x2 + c[i] - 1) / c[i];
      ord[i] = i;
    }
    Arrays.sort(ord, (i, j) -> c[i] - c[j]);
    boolean yes = false;
    int k1 = 1, k2 = 1;
    for (; k1 < n; k1++) {
      if (k1Min[ord[n - k1]] <= k1) break;
    }
    if (k1 < n) {
      for (; k1 + k2 <= n; k2++) {
        if (k2Min[ord[n - k1 - k2]] <= k2) break;
      }
      if (k1 + k2 <= n) {
        yes = true;
        io.println("Yes");
        io.printf("%d %d\n", k1, k2);
        for (int i = 0; i < k1; i++) {
          io.printf("%d ", ord[n - 1 - i] + 1);
        }
        io.println();
        for (int i = 0; i < k2; i++) {
          io.printf("%d ", ord[n - 1 - k1 - i] + 1);
        }
        io.println();
      }
    }
    if (!yes) {
      k1 = k2 = 1;
      for (; k2 < n; k2++) {
        if (k2Min[ord[n - k2]] <= k2) break;
      }
      if (k2 < n) {
        for (; k2 + k1 <= n; k1++) {
          if (k1Min[ord[n - k2 - k1]] <= k1) break;
        }
        if (k1 + k2 <= n) {
          yes = true;
          io.println("Yes");
          io.printf("%d %d\n", k1, k2);
          for (int i = 0; i < k1; i++) {
            io.printf("%d ", ord[n - 1 - k2 - i] + 1);
          }
          io.println();
          for (int i = 0; i < k2; i++) {
            io.printf("%d ", ord[n - 1 - i] + 1);
          }
          io.println();
        }
      }
    }
    if (!yes) io.println("No");
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
