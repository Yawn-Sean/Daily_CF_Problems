import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/275/B">B. Convex Shape</a>
 * <p>Author: nhant
 * <p>2025-05-22 07:08:38 +0700
 **/
public class B {
  IO io;
  
  void solve() {
    int n = io.ni(), m = io.ni();
    boolean[][] g = new boolean[n][m];
    /*
    quad1, quad2, quad3, quad4:
    10, 11, 11, 01
    11, 10, 01, 11
     */
    int cntb = 0, quad1L = m, quad1B = -1, quad2T = n, quad2L = m, quad3T = n, quad3R = -1, quad4B = -1, quad4R = -1;
    for (int i = 0; i < n; i++) {
      String s = io.next();
      for (int j = 0; j < m; j++) {
        g[i][j] = s.charAt(j) == 'B';
        if (g[i][j]) {
          cntb++;
        }
        if (i > 0 && j > 0) {
          if (g[i - 1][j - 1] && !g[i - 1][j] && g[i][j - 1] && g[i][j]) {
            quad1L = min(quad1L, j - 1);
            quad1B = max(quad1B, i);
          }
          if (g[i - 1][j - 1] && g[i - 1][j] && g[i][j - 1] && !g[i][j]) {
            quad2T = min(quad2T, i - 1);
            quad2L = min(quad2L, j - 1);
          }
          if (g[i - 1][j - 1] && g[i - 1][j] && !g[i][j - 1] && g[i][j]) {
            quad3T = min(quad3T, i - 1);
            quad3R = max(quad3R, j);
          }
          if (!g[i - 1][j - 1] && g[i - 1][j] && g[i][j - 1] && g[i][j]) {
            quad4B = max(quad4B, i);
            quad4R = max(quad4R, j);
          }
        }
      }
    }
    final int[][] dirs = new int[][]{{-1,0},{0,1},{1,0},{0,-1}};
    boolean[][] vis = new boolean[n][m];
    int compsz = 0;

    for (int i = 0; i < n && compsz == 0; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j]) {
          Queue<int[]> q = new ArrayDeque<>();
          vis[i][j] = true;
          q.add(new int[]{i, j});

          while (q.size() > 0) {
            int[] u = q.poll();
            compsz++;

            for (int[] d : dirs) {
              int nr = u[0] + d[0], nc = u[1] + d[1];

              if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.add(new int[]{nr, nc});
              }
            }
          }
          break;
        }
      }
    }
    boolean no = compsz != cntb || quad1L < quad4R || quad1B > quad2T || quad2L < quad3R || quad3T < quad4B;
    io.println(no ? "NO" : "YES");
  }
  
  void run() {
    try {
      io = new IO();
      solve();
    } finally {
      io.close();
    }
  }
  
  public static void main(String[] args) {
    (new B()).run();
  }
  
  static class IO extends PrintWriter {
    final private BufferedReader r;
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
      } catch (Exception ignored) {
      }
      return null;
    }
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
