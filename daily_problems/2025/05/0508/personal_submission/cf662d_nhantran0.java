import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/662/D">D. International Olympiad</a>
 * <p>Author: nhant
 * <p>2025-05-09 06:50:55 +0800
 * https://codeforces.com/problemset/submission/662/318887756
 **/
public class D {
  static IO io;

  private static String prefixOf(String s) {
    int n = s.length();
    if (n == 1) {
      return (s.compareTo("9") >= 0 ? "198" : "199");
    } else if (n == 2) {
      return (s.compareTo("99") >= 0 ? "19" : "20");
    } else if (n == 3) {
      return (s.compareTo("099") >= 0 ? "2" : "3");
    } else {
      StringBuilder t = new StringBuilder("9903");
      while (t.length() < n) {
        t.append('1');
      }
      return s.compareTo(t.reverse().toString()) >= 0 ? "" : "1";
    }
  }

  private static void solve() {
    String s = io.next();
    s = s.substring(s.indexOf('\'') + 1);
    io.println(prefixOf(s) + s);
  }

  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.ni();
      while (tc-- > 0) {
        solve();
      }
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
