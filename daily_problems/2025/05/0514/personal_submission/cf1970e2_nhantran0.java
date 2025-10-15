import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1970/E2">E2. Trails (Medium)</a>
 * <p>Author: nhant
 * <p>2025-05-15 01:40:37 +0800
 * https://codeforces.com/problemset/submission/1970/319706377
 **/
public class E2 {
  static IO io;
  static final int MOD = (int)1e9 + 7;
  
  private static void solve() {
    int m = io.ni(), n = io.ni();
    int[] s = new int[m], l = new int[m];
    for (int i = 0; i < m; i++) {
      s[i] = io.ni();
    }
    for (int i = 0; i < m; i++) {
      l[i] = io.ni();
    }
    Matrix a = new Matrix(m);
    a.a[0][0] = 1;
    Matrix t = new Matrix(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        t.a[i][j] = (t.a[i][j] + (int) ((long) s[i] * (s[j] + l[j]) % MOD) + (int) ((long) l[i] * s[j] % MOD)) % MOD;
      }
    }
    a = a.mul(t.pow(n));
    int res = 0;
    for (int[] row : a.a) {
      for (int v : row) {
        res = (res + v) % MOD;
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

  static class Matrix {
    int n;
    int[][] a;
    Matrix(int n) {
      this.n = n;
      a = new int[n][n];
    }
    Matrix mul(Matrix b) {
      Matrix res = new Matrix(n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            res.a[i][j] = (res.a[i][j] + (int)((long) a[i][k] * b.a[k][j] % MOD)) % MOD;
          }
        }
      }
      return res;
    }
    Matrix pow(int b) {
      Matrix res = new Matrix(n);
      for (int i = 0; i < n; i++) res.a[i][i] = 1;
      Matrix c = new Matrix(n);
      for (int i = 0; i < n; i++) {
        System.arraycopy(a[i], 0, c.a[i], 0, n);
      }
      for (; b > 0; b >>= 1) {
        if ((b & 1) == 1) {
          res = res.mul(c);
        }
        c = c.mul(c);
      }
      return res;
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
