import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/509/C">C. Sums of Digits</a>
 * <p>Author: nhant
 * <p>2025-04-16 17:16:44 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/509/315834464">Apr/16/2025 21:11UTC+8</a>
 **/
public class C {
  static IO io;
  static int[] x; // representation of a very large number where x[i] in [0;9] is the i-th digit of x, x[0] is unit digit

  private static void next(int xb, int b) {
    for (int i = 0; i < x.length; i++) {
      if (xb < b && x[i] < 9 && b - xb <= 9 - x[i] + 9 * i) {
        b -= xb;
        int d = Math.max(1, b - 9 * i);
        b -= d;
        x[i] += d;
        for (int j = 0; b > 0; b -= d, j++) {
          d = Math.min(b, 9);
          x[j] += d;
        }
        break;
      } else {
        xb -= x[i];
        x[i] = 0;
      }
    }
  }

  private static void solve() {
    int n = io.nextInt();
    int[] b = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = io.nextInt();
    }
    x = new int[400];
    for (int i = 0, prevB = 0; i < n; i++) {
      next(prevB, b[i]);
      StringBuilder s = new StringBuilder();
      for (int j = x.length - 1; j >= 0; j--) {
        if (x[j] == 0 && s.isEmpty()) continue;
        s.append((char) ('0' + x[j]));
      }
      io.println(s);
      prevB = b[i];
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
      super(o, true);
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
