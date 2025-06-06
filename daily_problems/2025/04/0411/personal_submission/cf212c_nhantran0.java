import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/212/C">C. Cowboys</a>
 **/
public class C {
  static IO io;

  private static void calc(char[] s, int[] a, int[] b) {
    for (int i = 1; i < s.length; i++) {
      if (s[i - 1] == 'A') {
        a[i] = a[i - 1] + b[i - 1];
        if (s[i] == 'B') {
          b[i] = b[i - 1];
        }
      } else {
        a[i] = b[i - 1];
        if (s[i] == 'A') {
          b[i] = a[i - 1];
        } else {
          b[i] = b[i - 1];
        }
      }
    }
  }
  
  private static void solve() {
    char[] s = io.next().toCharArray();
    int n = s.length;
    int[] a = new int[n], b = new int[n];
    a[0] = 1;
    calc(s, a, b);
    int res;
    if (s[n - 1] == 'B') {
      res = b[n - 1];
    } else {
      res = a[n - 1] + b[n - 1];
    }
    Arrays.fill(a, 0);
    Arrays.fill(b, 0);
    b[0] = 1;
    calc(s, a, b);
    if (s[0] == 'A' && s[n - 1] == 'B') {
      res += a[n - 1];
    } else if (s[0] == 'B') {
      res += b[n - 1];
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
