import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/367/B">B. Sereja ans Anagrams</a>
 * <p>Author: nhant
 * <p>2025-04-30 00:19:44 +0800
 * https://codeforces.com/contest/367/submission/317765330, 640 ms, 28800 KB. Map is slow.
 **/
public class B {
  static IO io;

  private static void solve() {
    int n = io.ni(), m = io.ni(), p = io.ni();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = io.ni();
    }
    Map<Integer, Integer> fb = new HashMap<>();
    for (int i = 0; i < m; i++) {
      int b = io.ni();
      fb.compute(b, (k, v) -> v == null ? 1 : v + 1);
    }
    boolean[] pok = new boolean[n];
    int res = 0;
    Map<Integer, Integer> fa = new HashMap<>();
    for (int i = 0; i < p; i++) {
      if (i + (long) (m - 1) * p >= n) break;
      fa.clear();
      int match = 0, len = 0;
      for (int j = i; j < n; j += p) {
        if (!fb.containsKey(a[j])) {
          fa.clear();
          match = 0;
          len = 0;
          continue;
        }
        len++;
        int acnt = fa.compute(a[j], (k, v) -> v == null ? 1 : v + 1);
        int bcnt = fb.get(a[j]);
        if (acnt == bcnt) {
          match++;
        }
        if (len > m) {
          len--;
          int l = j - m * p;
          acnt = fa.compute(a[l], (k, v) -> v - 1);
          bcnt = fb.get(a[l]);
          if (acnt == bcnt - 1) match--;
        }
        if (match == fb.size()) {
          res++;
          pok[j - (m - 1) * p] = true;
        }
      }
    }
    io.println(res);
    if (res > 0) {
      for (int i = 0; i < n; i++) if (pok[i]) io.printf("%d ", i + 1);
    }
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
