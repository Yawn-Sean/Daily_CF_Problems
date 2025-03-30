import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/757/D">D. Felicity's Big Secret Revealed</a>
 * Author: nhant
 * 2025-03-31 03:40:00 +0800
 **/
public class D {
  static IO io;

  private static void solve() {
    final int MD = (int) 1e9 + 7;
    int n = io.nextInt();
    char[] s = io.next().toCharArray();
    final int K = (1 << 20);
    int[][] g = new int[n + 1][K];
    boolean[] valid = new boolean[K];
    valid[0] = true;
    for (int mask = 1; mask < K; mask++) {
      valid[mask] = mask == (1 << Integer.bitCount(mask)) - 1;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
      for (int mask = 1; mask < K; mask++) {
        if (valid[mask]) {
          res = (res + g[i][mask]) % MD;
        }
      }
      if (i == n) break;
      int x = 0;
      for (int j = i; j < n; j++) {
        x = (x << 1) | (s[j] == '1' ? 1 : 0);
        if (x == 0) continue;
        if (x > 20) break;
        for (int mask = 0; mask < K; mask++) {
          int newMask = mask | (1 << (x - 1));
          if (mask == 0) {
            g[j + 1][newMask] = (g[j + 1][newMask] + 1) % MD;
          } else {
            g[j + 1][newMask] = (g[j + 1][newMask] + g[i][mask]) % MD;
          }
        }
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
