import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1092/C">C. Prefixes and Suffixes</a>
 * <p>Author: nhant
 * <p>2025-04-23 17:36:13 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/1092/316795427">Apr/23/2025 18:29UTC+8</a>
 **/
public class C {
  static IO io;

  static boolean isPreSuf(char[] pre, char[] suf, int matchLen) {
    for (int i = 0; i < matchLen; i++) {
      if (pre[pre.length - matchLen + i] != suf[i]) return false;
    }
    return true;
  }

  static boolean startsWith(char[] s, char[] t) { // s.length > t.length
    for (int i = 0; i < t.length; i++) {
      if (s[i] != t[i]) return false;
    }
    return true;
  }

  static boolean endsWith(char[] s, char[] t) {
    for (int i = 0; i < t.length; i++) {
      if (s[s.length - 1 - i] != t[t.length - 1 - i]) return false;
    }
    return true;
  }

  private static void solve() {
    int n = io.nextInt();
    int m = 2 * n - 2;
    char[][] s = new char[m][];
    int[] cnt = new int[n];
    int[][] l2i = new int[n][2]; // length to idx
    for (int i = 0; i < m; i++) {
      s[i] = io.next().toCharArray();
      int j = s[i].length;
      l2i[j][cnt[j]++] = i;
    }
    char[] res = new char[m];
    if (n == 2) {
      res[0] = 'P';
      res[1] = 'S';
    } else {
      boolean ma1 = isPreSuf(s[l2i[n - 1][0]], s[l2i[n - 1][1]], n - 2);
      int preCnt = (startsWith(s[l2i[n - 1][0]], s[l2i[n - 2][0]]) ? 1 : 0) +
          (startsWith(s[l2i[n - 1][0]], s[l2i[n - 2][1]]) ? 1 : 0);
      int sufCnt = (endsWith(s[l2i[n - 1][1]], s[l2i[n - 2][0]]) ? 1 : 0) +
          (endsWith(s[l2i[n - 1][1]], s[l2i[n - 2][1]]) ? 1 : 0);
      char[] t = new char[n];
      if (ma1 && preCnt >= 1 && sufCnt >= 1) {
        for (int i = 0, preI = l2i[n - 1][0]; i < n - 1; i++) {
          t[i] = s[preI][i];
        }
        t[n - 1] = s[l2i[n - 1][1]][n - 2];
      } else {
        for (int i = 0, preI = l2i[n - 1][1]; i < n - 1; i++) {
          t[i] = s[preI][i];
        }
        t[n - 1] = s[l2i[n - 1][0]][n - 2];
      }
      for (int i = 0; i < m; i++) {
        if (startsWith(t, s[i]) && cnt[s[i].length] > 0) {
          res[i] = 'P';
          cnt[s[i].length] = -cnt[s[i].length];
        } else {
          res[i] = 'S';
        }
      }
    }
    io.println(new String(res));
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
