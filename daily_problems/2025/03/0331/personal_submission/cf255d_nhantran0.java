import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/255/D">D. Mr. Bender and Square</a>
 * Author: nhant
 * 2025-04-01 00:31:51 +0800
 **/
public class D {
  static IO io;

  private static void solve() {
    int n = io.nextInt();
    int x = io.nextInt();
    int y = io.nextInt();
    int c = io.nextInt();
    int lo = 0, hi = 2 * n;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (c <= f(mi, x, y, n)) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    io.println(hi);
  }

  private static long f(int t, int x, int y, int n) {
    long all = 1 + (1L + t) * t * 2;
    int dt = x - 1, dr = n - y, db = n - x, dl = y - 1; // dist to top/right/bottom/left
    long top = t > dt ? sideTriangle(t - dt) : 0;
    long right = t > dr ? sideTriangle(t - dr) : 0;
    long bottom = t > db ? sideTriangle(t - db) : 0;
    long left = t > dl? sideTriangle(t - dl) : 0;
    long topLeft = t - 1 > dt + dl ? cornerTriangle(t - 1 - dt - dl) : 0;
    long topRight = t - 1 > dt + dr ? cornerTriangle(t - 1 - dt - dr) : 0;
    long bottomLeft = t - 1 > db + dl ? cornerTriangle(t - 1 - db - dl) : 0;
    long bottomRight = t - 1 > db + dr ? cornerTriangle(t - 1 - db - dr) : 0;
    return all - top - right - bottom - left + topLeft + topRight + bottomLeft + bottomRight;
  }

  private static long sideTriangle(long h) {
    return 2 * (1 + h) * h / 2 - h; // sum of (2*k-1), k=1..h
  }

  private static long cornerTriangle(long h) {
    return (1 + h) * h / 2;
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
