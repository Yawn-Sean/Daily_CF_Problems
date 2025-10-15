import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/691/C">C. Exponential notation</a>
 * Author: nhant
 * 2025-04-01 18:23:13 +0800
 **/
public class C {
  static IO io;

  private static void solve() {
    char[] s = io.next().toCharArray();
    int n = s.length, firstNumI = -1, dotI = n, lastNumI = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') dotI = i;
      else if (s[i] != '0') {
        if (firstNumI == -1) firstNumI = i;
        lastNumI = i;
      }
    }
    StringBuilder sb = new StringBuilder();
    sb.append(s[firstNumI]);
    // decimal part .yzt
    if (firstNumI < lastNumI) {
      sb.append('.');
      for (int i = firstNumI + 1; i <= lastNumI; i++) {
        if (s[i] != '.') sb.append(s[i]);
      }
    }
    // x is not a.yzt, dot doesn't go immediately after first non-0 digit
    if (firstNumI + 1 != dotI) {
      sb.append(firstNumI < dotI ? "E" : "E-");
      int p = firstNumI < dotI ? dotI - firstNumI - 1 : firstNumI - dotI;
      Stack<Character> st = new Stack<>();
      while (p > 0) {
        st.add((char) ('0' + (p % 10)));
        p /= 10;
      }
      while (!st.isEmpty()) {
        sb.append(st.pop());
      }
    }
    io.println(sb);
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
