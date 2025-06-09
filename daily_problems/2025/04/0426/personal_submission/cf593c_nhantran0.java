import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/593/C">C. Beautiful Function</a>
 * <p>Author: nhant
 * <p>2025-04-27 02:37:55 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/593/317384366">Apr/27/2025 03:53UTC+8, 265 ms, 1200 KB</a>
 **/
public class C {
  static IO io;

  private static void solve() {
    int n = io.ni();
    String rx = "", ry = "";
    for (int i = 0; i < n; i++) {
      int x = io.ni(), y = io.ni(), r = io.ni();
      String nx = String.format("(%d*((1-abs((t-%d)))+abs((1-abs((t-%d))))))", x/2, i, i);
      String ny = String.format("(%d*((1-abs((t-%d)))+abs((1-abs((t-%d))))))", y/2, i, i);
      if (i == 0) {
        rx = nx;
        ry = ny;
      } else {
        rx = String.format("(%s+%s)", rx, nx);
        ry = String.format("(%s+%s)", ry, ny);
      }
    }
    io.println(rx);
    io.println(ry);
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
