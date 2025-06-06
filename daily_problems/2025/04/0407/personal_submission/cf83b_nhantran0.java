import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/83/B">B. Doctor</a>
 * <p>Author: nhant
 * <p>2025-04-07 18:30:34 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/83/314349664">Apr/07/2025 19:12UTC+8</a>
 **/
public class B {
  static IO io;

  // true if total # of served customers <= k
  // false if > k
  private static boolean f(int rnd, long k, int[] nums) {
    for (int x : nums) {
      k -= Math.min(x, rnd);
      if (k < 0) return false;
    }
    return true;
  }

  private static void solve() {
    int n = io.nextInt();
    long k = io.nextLong();
    int[] a = new int[n];
    long total = 0;
    int maxA = 0;
    for (int i = 0; i < n; i++) {
      a[i] = io.nextInt();
      total += a[i];
      if (maxA < a[i]) maxA = a[i];
    }
    if (total < k) io.println(-1);
    else if (total == k) io.println();
    else {
      int lo = 0, hi = maxA;
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (f(mi, k, a)) {
          lo = mi;
        } else {
          hi = mi - 1;
        }
      }
      for (int i = 0; i < n; i++) {
        int d = Math.min(a[i], lo);
        a[i] -= d;
        k -= d;
      }
      int start = 0;
      for (; start < n && k > 0; start++) {
        if (a[start] > 0) {
          a[start]--;
          k--;
        }
      }
      for (int i = 0; i < n; i++) {
        int j = start + i >= n ? start + i - n : start + i;
        if (a[j] > 0) {
          io.printf("%d ", j + 1);
        }
      }
      io.println();
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

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
