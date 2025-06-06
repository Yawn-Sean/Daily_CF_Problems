import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/616/C">C. The Labyrinth</a>
 * <p>Author: nhant
 * <p>2025-04-26 15:16:59 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/616/317272392">Apr/26/2025 15:43UTC+8, 312 ms, 2000 KB</a>
 **/
public class C {
  static IO io;
  static int[] d;
  static int get(int x) {
    return d[x] < 0 ? x : (d[x] = get(d[x]));
  }
  static boolean unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (-d[x] < -d[y]) {
      int t = x;
      x = y;
      y = t;
    }
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  private static void solve() {
    final int[][] dirs = new int[][]{{-1,0},{0,1},{1,0},{0,-1}};
    int n = io.ni(), m = io.ni();
    char[][] s = new char[n][];
    for (int i = 0; i < n; i++) {
      s[i] = io.next().toCharArray();
    }
    d = new int[n * m];
    Arrays.fill(d, -1);
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (s[r][c] == '*') continue;
        int x = r * m + c;
        for (int[] st : dirs) {
          int nr = r + st[0], nc = c + st[1];
          if (nr < 0 || nr >= n || nc < 0 || nc >= m || s[nr][nc] == '*') continue;
          unite(x, nr * m + nc);
        }
      }
    }
    char[] res = new char[m];
    int[] had = new int[4];
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (s[r][c] == '.') {
          res[c] = '.';
        } else {
          Arrays.fill(had, -1);
          int sz = 1;
          int i = 0;
          for (int[] st : dirs) {
            int nr = r + st[0], nc = c + st[1];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && s[nr][nc] == '.') {
              int px = get(nr * m + nc);
              boolean dup = false;
              for (int j = i - 1; j >= 0; j--) {
                if (px == had[j]) {
                  dup = true;
                  break;
                }
              }
              if (!dup) {
                sz += -d[px];
                had[i++] = px;
              }
            }
          }
          res[c] = (char) ('0' + (sz % 10));
        }
      }
      io.println(new String(res));
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
