import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/766/C">C. Mahmoud and a Message</a>
 * Author: nhant
 * 2025-04-02 23:00:06 +0800
 **/
public class C {
  static IO io;
  private static final int MD = (int) 1e9+7;

  private static int add(int a, int b) {
    a += b;
    if (a >= MD) a -= MD;
    return a;
  }
  
  private static void solve() {
    int n = io.nextInt();
    char[] s = io.next().toCharArray();
    int[] a = new int[26];
    for (int i = 0; i < a.length; i++) {
      a[i] = io.nextInt();
    }
    int[] f = new int[n];
    int[] g = new int[n];
    Arrays.fill(g, n);
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
      int maxSubLen = a[s[i] - 'a'];
      for (int j = i - 1; j >= -1 && i - j <= maxSubLen; j--) {
        maxLen = Math.max(maxLen, i - j);
        if (j == -1) {
          f[i] = add(f[i], 1);
          g[i] = 1;
        } else {
          f[i] = add(f[i], f[j]);
          g[i] = Math.min(g[i], g[j] + 1);
          maxSubLen = Math.min(maxSubLen, a[s[j] - 'a']);
        }
      }
    }
    io.printf("%d\n%d\n%d\n", f[n - 1], maxLen, g[n - 1]);
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
