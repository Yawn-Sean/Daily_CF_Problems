import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/412/E">E. E-mail Addresses</a>
 * <p>Author: nhant
 * <p>2025-04-09 02:12:31 +0800
 * <p>Submission: <a href=""></a>
 **/
public class E {
  static IO io;

  private static boolean isLetter(char c) {
    return 'a' <= c && c <= 'z';
  }

  private static boolean isNumber(char c) {
    return '0' <= c && c <= '9';
  }

  private static void solve() {
    char[] s = io.next().toCharArray();
    long res = 0;
    for (int i = 0; i < s.length; i++) {
      if (s[i] == '@') {
        int cntStart = 0;
        for (int j = i - 1; j >= 0; j--) {
          if (s[j] == '@' || s[j] == '.') break;
          if (isLetter(s[j])) cntStart++;
        }
        int j = i + 1;
        while (j < s.length && (isLetter(s[j]) || isNumber(s[j]))) {
          j++;
        }
        if (j == s.length) break;
        if (j == i + 1) continue;
        else if (s[j] != '.') {
          i = j - 1; // s[j] can be @
          continue;
        }
        j++;
        while (j < s.length && isLetter(s[j])) {
          res += cntStart;
          j++;
        }
        i = j - 1;
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
