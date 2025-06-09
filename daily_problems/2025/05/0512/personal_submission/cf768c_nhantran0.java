import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/768/C">C. Jon Snow and his Favourite Number</a>
 * <p>Author: nhant
 * <p>2025-05-12 11:11:09 +0800
 * https://codeforces.com/problemset/submission/768/319341989, O(N + K * MAX_A)
 **/
public class C {
  static IO io;

  private static void solve() {
    int n = io.ni(), k = io.ni(), x = io.ni();
    int MAX_A = 1024;
    int[] f = new int[MAX_A];
    int[] g = new int[MAX_A];
    for (int i = 0; i < n; i++) {
      int v = io.ni();
      f[v]++;
      g[v] = f[v];
    }
    while (k-- > 0) {
      int cnt = 0;
      for (int i = 0; i < MAX_A; i++) {
        if (f[i] > 0) {
          int d = (cnt % 2 == 0) ? ((f[i] + 1) / 2) : (f[i] / 2);
          g[i] -= d;
          g[i ^ x] += d;
          cnt += f[i];
        }
      }
      System.arraycopy(g, 0, f, 0, MAX_A);
    }
    int min = MAX_A, max = -1;
    for (int i = 0; i < MAX_A; i++) {
      if (f[i] > 0) {
        if (min == MAX_A) min = i;
        max = i;
      }
    }
    io.printf("%d %d\n", max, min);
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
