import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1938/C">C. Bit Counting Sequence</a>
 * <p>Author: nhant
 * <p>2025-04-08 00:56:56 +0800
 * <p>Submission: <a href="https://codeforces.com/contest/1938/submission/314416338">Apr/08/2025 03:17UTC+8</a>
 **/
public class C {
  static IO io;

  private static long calc(int[] a, int n) {
    int done = 0;
    long x = 0;
    if (n > 1) {
      for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d > 1 || a[i] == 0) {
          return -1;
        }
        long prevPart = (1L << (1 - d)) - 1;
        int newDone = 1 - d + 1;
        long mask = (1L << Math.min(newDone, done)) - 1;
        if ((x & mask) != (prevPart & mask)) {
          return -1;
        }
        x |= prevPart;
        x++;
        done = Math.max(done, newDone);
      }
    }
    for (int i = 0, m = a[n - 1] - Long.bitCount(x); i < m; i++) {
      x |= (1L << (done + i));
    }
    return x - n + 1;
  }

  private static void solve() {
    int n = io.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = io.nextInt();
    }
    io.println(calc(a, n));
  }

  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.nextInt();
      while (tc-- > 0) {
        solve();
      }
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
