import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1277/D">D. Let's Play the Words?</a>
 **/
public class D {
  static IO io;

  static String reverseOf(String s) {
    StringBuilder rb = new StringBuilder(s.length());
    int m = s.length();
    for (int j = m - 1; j >= 0; j--) {
      rb.append(s.charAt(j));
    }
    return rb.toString();
  }

  private static void solve() {
    int n = io.nextInt();
    String[] s = new String[n];
    Set<String> set = new HashSet<>();
    List<Integer> i00 = new ArrayList<>(), i01 = new ArrayList<>(), i10 = new ArrayList<>(), i11 = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      s[i] = io.next();
      set.add(s[i]);
      char fi = s[i].charAt(0), la = s[i].charAt(s[i].length() - 1);
      if (fi == '0') {
        if (la == '0') {
          i00.add(i);
        } else {
          i01.add(i);
        }
      } else {
        if (la == '1') {
          i11.add(i);
        } else {
          i10.add(i);
        }
      }
    }
    if (!i00.isEmpty() && !i11.isEmpty() && i01.isEmpty() && i10.isEmpty()) {
      io.println(-1);
    } else {
      List<Integer> res = new ArrayList<>();
      int diff = i01.size() - i10.size();
      while (diff > 1) {
        int i = i01.removeLast();
        if (!set.contains(reverseOf(s[i]))) {
          res.add(i);
          diff -= 2;
        }
      }
      while (diff < -1) {
        int i = i10.removeLast();
        if (!set.contains(reverseOf(s[i]))) {
          res.add(i);
          diff += 2;
        }
      }
      io.println(res.size());
      for (int i : res) io.printf("%d ", i + 1);
      io.println();
    }
  }
  
  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.nextInt();
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
