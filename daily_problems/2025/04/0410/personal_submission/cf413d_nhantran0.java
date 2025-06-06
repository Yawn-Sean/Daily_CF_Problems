import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/413/D">D. 2048</a>
 **/
public class D {
  static IO io;

  static final int MD = (int) 1e9 + 7;

  static int add(int a, int b) {
    a += b;
    if (a >= MD) a -= MD;
    return a;
  }

  private static void solve() {
    int n = io.nextInt();
    int k = io.nextInt();
    int m = 1 << (k - 1);
    int[] f = new int[m], g = new int[m];
    f[0] = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int x = io.nextInt() / 2;
      if (x == 0) {
        res = add(res, res);
      }
      if (x != 2) {
        for (int j = 0; j < m - 1; j++) {
          g[j + 1] = add(g[j + 1], f[j]);
        }
        res = add(res, f[m - 1]);
      }
      if (x != 1) {
        for (int j = 1; j < m; j += 2) {
          g[2] = add(g[2], f[j]);
        }
        for (int j = 0; j < m - 2; j += 2) {
          g[j + 2] = add(g[j + 2], f[j]);
        }
        res = add(res, f[m - 2]);
      }
      for (int j = 0; j < m; j++) {
        f[j] = g[j];
        g[j] = 0;
      }
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
