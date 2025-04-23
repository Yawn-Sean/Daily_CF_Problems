import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/818/C">C. Sofa Thief</a>
 * <p>Author: nhant
 * <p>2025-04-23 23:11:46 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/818/316861206">Apr/24/2025 00:31UTC+8</a>
 **/
public class C {
  static IO io;

  private static void solve() {
    int d = io.nextInt();
    int n = io.nextInt();
    int m = io.nextInt();
    int[][] p = new int[d][4];
    int[] xl = new int[n + 2], xr = new int[n + 2];
    int[] yt = new int[m + 2], yb = new int[m + 2];
    for (int i = 0; i < d; i++) {
      p[i][0] = io.nextInt();
      p[i][1] = io.nextInt();
      p[i][2] = io.nextInt();
      p[i][3] = io.nextInt();
      xl[Math.min(p[i][0], p[i][2])]++;
      xr[Math.max(p[i][0], p[i][2])]++;
      yt[Math.min(p[i][1], p[i][3])]++;
      yb[Math.max(p[i][1], p[i][3])]++;
    }
    int reqCntL = io.nextInt(), reqCntR = io.nextInt(), reqCntT = io.nextInt(), reqCntB = io.nextInt();
    for (int i = 1; i <= n; i++) {
      xl[i] += xl[i - 1];
      xr[n + 1 - i] += xr[n + 2 - i];
    }
    for (int i = 1; i <= m; i++) {
      yt[i] += yt[i - 1];
      yb[m + 1 - i] += yb[m + 2 - i];
    }
    int res = 0;
    for (int i = 0; i < d; i++) {
      int lx = Math.min(p[i][0], p[i][2]), rx = Math.max(p[i][0], p[i][2]);
      int ty = Math.min(p[i][1], p[i][3]), by = Math.max(p[i][1], p[i][3]);
      int cntl = xl[rx - 1] - (lx < rx ? 1 : 0);
      int cntr = xr[lx + 1] - (lx < rx ? 1 : 0);
      int cntt = yt[by - 1] - (ty < by ? 1 : 0);
      int cntb = yb[ty + 1] - (ty < by ? 1 : 0);
      if (cntl == reqCntL && cntr == reqCntR && cntt == reqCntT && cntb == reqCntB) {
        res = i + 1;
        break;
      }
    }
    io.println(res == 0 ? -1 : res);
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
