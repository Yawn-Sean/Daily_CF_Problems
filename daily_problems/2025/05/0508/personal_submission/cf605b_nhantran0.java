import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/605/B">B. Lazy Student</a>
 * <p>Author: nhant
 * <p>2025-05-08 19:45:28 +0800
 * https://codeforces.com/problemset/submission/605/318846697, O(N + M)
 **/
public class B {
  static IO io;

  private static void solve() {
    int n = io.ni(), m = io.ni();
    int[] a = new int[m], b = new int[m];
    int[][] e = new int[2][m];
    int[] mn = new int[n + 1];
    Arrays.fill(mn, (int)1e9 + 10);
    Integer[] ord = new Integer[m];
    for (int i = 0; i < m; i++) {
      a[i] = io.ni();
      b[i] = io.ni();
      ord[i] = i;
    }
    Arrays.sort(ord, (i, j) -> b[i] != b[j] ? b[j] - b[i] : a[i] - a[j]);
    int u1 = 1, v1 = 2, u0 = 2, v0 = 3;
    mn[1] = a[ord[0]];
    for (int i = 0; i < n - 1; i++) {
      e[0][ord[i]] = u1;
      e[1][ord[i]] = v1;
      mn[v1] = a[ord[i]];
      v1++;
    }
    boolean ok = true;
    for (int i = n - 1; i < m; i++) {
      e[0][ord[i]] = u0;
      e[1][ord[i]] = v0;
      if (mn[v0] > a[ord[i]]) {
        ok = false;
        break;
      }
      u0++;
      if (u0 == v0) {
        v0++;
        u0 = 2;
      }
    }
    if (!ok) {
      io.println(-1);
    } else {
      for (int i = 0; i < m; i++) {
        io.printf("%d %d\n", e[0][i], e[1][i]);
      }
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
