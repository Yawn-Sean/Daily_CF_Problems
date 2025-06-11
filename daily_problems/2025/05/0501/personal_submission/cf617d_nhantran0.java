import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/617/D">D. Polyline</a>
 * <p>Author: nhant
 * <p>2025-05-02 02:05:51 +0800
 * https://codeforces.com/problemset/submission/617/318029697, 265 ms, 800 KB
 **/
public class D {
  static IO io;

  static boolean out(int v, int p1, int p2) {
    return v <= Math.min(p1, p2) || v >= Math.max(p1, p2);
  }

  private static void solve() {
    int[] x = new int[3], y = new int[3];
    for (int i = 0; i < 3; i++) {
      x[i] = io.ni();
      y[i] = io.ni();
    }
    int res = 3;
    if ((x[0] == x[1] && x[0] == x[2]) || (y[0] == y[1] && y[1] == y[2])) {
      res = 1;
    } else if ((x[0] == x[1] && out(y[2], y[0], y[1])) ||
        (x[0] == x[2] && out(y[1], y[0], y[2])) ||
        (x[1] == x[2] && out(y[0], y[1], y[2])) ||
        (y[0] == y[1] && out(x[2], x[0], x[1])) ||
        (y[0] == y[2] && out(x[1], x[0], x[2])) ||
        (y[1] == y[2] && out(x[0], x[1], x[2]))) {
      res = 2;
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
