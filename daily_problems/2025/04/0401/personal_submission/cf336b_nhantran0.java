import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Math.sqrt;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/336/B">B. Vasily the Bear and Fly</a>
 * Author: nhant
 * 2025-04-02 02:32:59 +0800
 **/
public class B {
  static IO io;

  private static void solve() {
    int m = io.nextInt();
    int R = io.nextInt();
    double res = 2 * R * (m + (2 + sqrt(2)) * (m - 1) + ((long) m - 1) * (m - 2) * (sqrt(2) + m / 3.0)) / m / m;
    io.printf("%.10f\n", res);
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
