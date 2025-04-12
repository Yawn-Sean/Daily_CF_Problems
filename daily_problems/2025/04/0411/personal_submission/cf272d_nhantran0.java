import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/272/D">D. Dima and Two Sequences</a>
 * <p>Author: nhant
 * <p>2025-04-11 23:41:04 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/272/315039763">Apr/12/2025 01:18UTC+8</a>
 **/
public class D {
  static IO io;

  static int m;

  static int mul(int a, int b) {
    return (int) ((long) a * b % m);
  }

  static int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
      if (b % 2 == 1) res = mul(res, a);
      a = mul(a, a);
      b /= 2;
    }
    return res;
  }

  private static void solve() {
    int n = io.nextInt();
    int n2 = n * 2;
    int[][] a = new int[n2][2];
    for (int i = 0; i < n; i++) {
      a[i][0] = io.nextInt();
      a[i][1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
      a[n + i][0] = io.nextInt();
      a[n + i][1] = i + 1;
    }
    m = io.nextInt();
    Arrays.sort(a, (u, v) -> u[0] != v[0] ? u[0] - v[0] : u[1] - v[1]);
    int res = 1, pow2 = 0;
    for (int i = 1, k = 1; i < n2; i++) {
      if (a[i][0] == a[i - 1][0]) {
        int v = ++k;
        while (v % 2 == 0) {
          v /= 2;
          pow2++;
        }
        res = mul(res, v);
        if (a[i][1] == a[i - 1][1]) {
          pow2--;
        }
      } else {
        k = 1;
      }
    }
    res = mul(res, pow(2, pow2));
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
