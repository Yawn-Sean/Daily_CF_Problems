import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/490/D">D. Chocolate</a>
 * <p>Author: nhant
 * <p>2025-04-23 01:43:09 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/490/316728532">Apr/23/2025 02:39UTC+8</a>
 **/
public class D {
  static IO io;

  static int[] reduce(int v) {
    int c2 = 0, c3 = 0;
    while (v > 0 && v % 2 == 0) {
      c2++;
      v /= 2;
    }
    while (v > 0 && v % 3 == 0) {
      c3++;
      v /= 3;
    }
    return new int[]{v, c2, c3};
  }

  private static void restore(int[] v) {
    while (v[1] > 0) {
      v[0] *= 2;
      v[1]--;
    }
    while (v[2] > 0) {
      v[0] *= 3;
      v[2]--;
    }
  }

  private static void solve() {
    int a1 = io.nextInt(), b1 = io.nextInt(), a2 = io.nextInt(), b2 = io.nextInt();
    int[] x1 = reduce(a1), y1 = reduce(b1), x2 = reduce(a2), y2 = reduce(b2);
    if ((long) x1[0] * y1[0] != (long) x2[0] * y2[0]) {
      io.println(-1);
      return;
    }
    int cnt = 0;
    while (x1[2] + y1[2] > x2[2] + y2[2]) {
      if (x1[2] > 0) {
        x1[2]--;
        x1[1]++;
      } else {
        y1[2]--;
        y1[1]++;
      }
      cnt++;
    }
    while (x1[2] + y1[2] < x2[2] + y2[2]) {
      if (x2[2] > 0) {
        x2[2]--;
        x2[1]++;
      } else {
        y2[2]--;
        y2[1]++;
      }
      cnt++;
    }
    while (x1[1] + y1[1] > x2[1] + y2[1]) {
      if (x1[1] > 0) x1[1]--;
      else y1[1]--;
      cnt++;
    }
    while (x1[1] + y1[1] < x2[1] + y2[1]) {
      if (x2[1] > 0) x2[1]--;
      else y2[1]--;
      cnt++;
    }
    restore(x1);
    restore(y1);
    restore(x2);
    restore(y2);
    io.printf("%d\n%d %d\n%d %d\n", cnt, x1[0], y1[0], x2[0], y2[0]);
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
