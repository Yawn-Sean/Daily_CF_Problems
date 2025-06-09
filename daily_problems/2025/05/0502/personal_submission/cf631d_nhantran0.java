import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/631/D">D. Messenger</a>
 * <p>Author: nhant
 * <p>2025-05-02 17:42:56 +0800
 * https://codeforces.com/problemset/submission/631/318093330, 358 ms, 9600 KB
 **/
public class D {
  static IO io;

  static int parse(char[] s, long[] cnt) {
    int len = 0;
    for (int i = 0; i < s.length; i++) {
      char[] a = io.next().toCharArray();
      int curCnt = 0;
      char ch = a[a.length - 1];
      for (char c : a) {
        if ('0' <= c && c <= '9') {
          curCnt = curCnt * 10 + (c - '0');
        }
      }
      if (len > 0 && ch == s[len - 1]) {
        cnt[len - 1] += curCnt;
      } else {
        s[len] = ch;
        cnt[len] = curCnt;
        len++;
      }
    }
    return len;
  }

  private static void solve() {
    int n = io.ni(), m = io.ni();
    char[] s = new char[n], t = new char[m];
    long[] sc = new long[n], tc = new long[m];
    int sl = parse(s, sc), tl = parse(t, tc);
    io.println(Arrays.toString(sc));
    long res = 0;
    if (tl == 1) {
      for (int i = 0; i < sl; i++) {
        if (s[i] == t[0] && sc[i] >= tc[0]) {
          res += sc[i] - tc[0] + 1;
        }
      }
    } else if (tl == 2) {
      for (int i = 0; i < sl - 1; i++) {
        if (s[i] == t[0] && sc[i] >= tc[0] && s[i + 1] == t[1] && sc[i + 1] >= tc[1]) {
          res++;
        }
      }
    } else {
      // t[1:-1] + '#' + s, t[i:j] is substring of t from index i..j-1
      int nu = tl - 1 + sl;
      char[] u = new char[nu];
      long[] uc = new long[nu];
      for (int i = 1; i < tl - 1; i++) {
        u[i - 1] = t[i];
        uc[i - 1] = tc[i];
      }
      u[tl - 1] = '#';
      for (int i = 0; i < sl; i++) {
        u[tl - 1 + i] = s[i];
        uc[tl - 1 + i] = sc[i];
      }
      int[] p = new int[nu];
      for (int i = 1; i < u.length - 1; i++) {
        int j = p[i - 1];
        while (j > 0 && (u[j] != u[i] || uc[j] != uc[i])) {
          j = p[j - 1];
        }
        if (u[j] == u[i] && uc[j] == uc[i]) {
          j++;
        }
        p[i] = j;
        if (j == tl - 2) {
          int fi = i - (tl - 2), la = i + 1; // idx of first & last to compare with t
          if (u[fi] == t[0] && uc[fi] >= tc[0] && u[la] == t[tl - 1] && uc[la] >= tc[tl - 1]) {
            res++;
          }
        }
      }
      io.println(Arrays.toString(p));
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

    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
