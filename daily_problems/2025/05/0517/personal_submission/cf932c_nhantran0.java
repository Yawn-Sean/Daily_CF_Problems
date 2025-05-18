import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/932/C">C. Permutation Cycle</a>
 * <p>Author: nhant
 * <p>2025-05-18 09:13:34 +0800
 * https://codeforces.com/problemset/submission/932/320168021
 **/
public class C {
  static IO io;
  
  private static void solve() {
    int n = io.ni(), a = io.ni(), b = io.ni();
    int ca = 0, cb = -1;
    for (; ca * a <= n; ca++) {
      if ((n - ca * a) % b == 0) {
        cb = (n - ca * a) / b;
        break;
      }
    }
    if (cb != -1) {
      int[] p = new int[n + 1];
      for (int k = 0; k < ca; k++) {
        for (int j = 1; j <= a; j++) {
          p[k * a + j] = (j == a ? k * a + 1 : k * a + j + 1);
        }
      }
      int os = ca * a;
      for (int k = 0; k < cb; k++) {
        for (int j = 1; j <= b; j++) {
          p[os + k * b + j] = os + (j == b ? k * b + 1 : k * b + j + 1);
        }
      }
      StringBuilder sb = new StringBuilder();
      for (int j = 1; j <= n; j++) {
        sb.append(p[j]).append(" ");
      }
      io.println(sb);
    } else {
      io.println(-1);
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
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
