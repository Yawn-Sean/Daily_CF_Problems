import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/603/A">A. Alternative Thinking</a>
 * <p>Author: nhant
 * <p>2025-04-19 02:45:49 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/603/316141201">Apr/19/2025 02:49UTC+8	</a>
 **/
public class A {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    char[] s = io.next().toCharArray();
    int flipCnt = 0, sameCnt = 0;
    for (int i = 1; i < s.length; i++) {
      if (s[i - 1] == s[i]) {
        sameCnt++;
      } else {
        flipCnt++;
      }
    }
    io.println(flipCnt + 1 + Math.min(2, sameCnt));
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
