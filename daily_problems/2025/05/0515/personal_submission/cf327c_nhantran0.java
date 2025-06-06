import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/327/C">C. Magic Five</a>
 * <p>Author: nhant
 * <p>2025-05-16 07:26:42 +0800
 * https://codeforces.com/problemset/submission/327/319835957
 **/
public class C {
  static IO io;
  static final int MOD = (int)1e9 + 7;

  static int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
  }

  static int mul(int a, int b) {
    return (int) ((long) a * b % MOD);
  }

  static int pow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1, a = mul(a, a)) {
      if ((b & 1) == 1) {
        res = mul(res, a);
      }
    }
    return res;
  }

  static int inv(int a) {
    return pow(a, MOD - 2);
  }
  
  private static void solve() {
    char[] a = io.next().toCharArray();
    int k = io.ni();
    int b = 0, cur = 1;
    for (char c : a) {
      if (c == '0' || c == '5') {
        b = (b + cur) % MOD;
      }
      cur = mul(cur, 2);
    }
    int m = a.length;
    int twoPowM = 1;
    for (int i = 0; i < m; i++) {
      twoPowM = mul(twoPowM, 2);
    }
    int res = mul(b, mul(sub(pow(twoPowM, k), 1), inv(sub(twoPowM, 1))));
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
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
