import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/552/D">D. Vanya and Triangles</a>
 * <p>Author: nhant
 * <p>2025-05-12 15:34:01 +0800
 * https://codeforces.com/problemset/submission/552/319403252
 **/
public class D {
  static IO io;
  static int[][] gcd;
  static int a, b, c;

  static void lineOf(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
      a = 1; b = 0; c = -x1;
    } else if (y1 == y2) {
      a = 0; b = 1; c = -y1;
    } else {
      int g = gcd[Math.abs(y1 - y2)][Math.abs(x2 - x1)];
      if (x2 - x1 < 0) {
        g = -g;
      }
      a = (y1 - y2) / g;
      b = (x2 - x1) / g;
      c = -a * x1 - b * y1;
    }
  }

  static long hashOf(int a, int b, int c) {
    return ((long)(a + 200) * 402 + (b + 200)) * 80002 + c + 40000;
  }

  private static void solve() {
    int n = io.ni();
    int[] x = new int[n], y = new int[n];
    for (int i = 0; i < n; i++) {
      x[i] = io.ni();
      y[i] = io.ni();
    }
    long res = 0;
    if (n >= 3) {
      int m = n * (n - 1) / 2;
      long[] lineHash = new long[m];
      int hi = 0;
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
          lineOf(x[i], y[i], x[j], y[j]);
          lineHash[hi++] = hashOf(a, b, c);
        }
      }
      Arrays.sort(lineHash);
      List<Integer> lineCnt = new ArrayList<>(); // count segments connecting 2 points in any line. NOT count of points.
      int cnt = 1;
      for (int i = 1; i < lineHash.length; i++) {
        if (lineHash[i] != lineHash[i - 1]) {
          lineCnt.add(cnt);
          cnt = 1;
        } else {
          cnt++;
        }
      }
      lineCnt.add(cnt);
      int[] ltp = new int[m + 1];
      for (int i = 0; i <= n; i++) {
        ltp[i * (i - 1) / 2] = i;
      }
      res = (long) n * (n - 1) * (n - 2) / 6;
      for (int l : lineCnt) {
        int p = ltp[l];
        res -= (long) p * (p - 1) * (p - 2) / 6;
      }
    }
    io.println(res);
  }

  public static void main(String[] args) {
    try {
      io = new IO();
      int MAX_X = 200;
      gcd = new int[MAX_X + 1][MAX_X + 1];
      for (int i = 0; i <= MAX_X; i++) {
        gcd[i][i] = i;
        for (int j = 0; j < i; j++) {
          gcd[i][j] = gcd[j][i] = (j == 0 ? i : gcd[j][i % j]);
        }
      }
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
