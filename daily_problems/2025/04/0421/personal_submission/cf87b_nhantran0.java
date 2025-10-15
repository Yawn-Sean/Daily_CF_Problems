import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/87/B">B. Vasya and Types</a>
 * <p>Author: nhant
 * <p>2025-04-22 01:41:37 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/87/316603042">Apr/22/2025 02:10UTC+8</a>
 **/
public class B {
  static IO io;
  
  private static void solve() {
    final String VOID = "void";
    final String ERRTYPE = "errtype";
    final int ERRTYPE_INT = 0;
    final int VOID_INT = 1;
    int n = io.nextInt();
    Map<String, int[]> mp = new HashMap<>();
    while (n-- > 0) {
      String op = io.next();
      String a = io.next();
      int re = 0, p = 0, l = 0, r = a.length() - 1;
      while (l < a.length() && a.charAt(l) == '&') {
        re++;
        l++;
      }
      while (r >= 0 && a.charAt(r) == '*') {
        p++;
        r--;
      }
      String k = a.substring(l, r + 1);
      int av, np = 0;
      if (k.equals(VOID)) {
        if (re <= p) {
          av = VOID_INT;
          np = p - re;
        } else {
          av = ERRTYPE_INT;
        }
      } else if (!k.equals(ERRTYPE) && mp.containsKey(k)) {
        int[] v = mp.get(k);
        if (v[0] == ERRTYPE_INT || v[1] + p - re < 0) {
          av = ERRTYPE_INT;
        } else {
          av = VOID_INT;
          np = v[1] + p - re;
        }
      } else { // k==errtype or (k!=void and k not in mp)
        av = ERRTYPE_INT;
      }
      if (op.charAt(4) == 'd') { // typedef
        mp.put(io.next(), new int[]{av, np});
      } else { // typeof
        if (av == VOID_INT) {
          io.printf(VOID);
          if (np > 0) io.printf("*".repeat(np));
          io.println();
        } else {
          io.println(ERRTYPE);
        }
      }
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
