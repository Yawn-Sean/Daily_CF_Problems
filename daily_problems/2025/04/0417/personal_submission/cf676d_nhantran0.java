import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/676/D">D. Theseus and labyrinth</a>
 * <p>Author: nhant
 * <p>2025-04-18 03:22:13 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/676/316016102">Apr/18/2025 03:52UTC+8</a>
 **/
public class D {
  static IO io;
  static boolean[][][] mask;

  private static void solve() {
    final int MAX_TIME = 10000000;
    int[][] dirs = new int[][]{{-1,0},{0,1},{1,0},{0,-1}};
    int n = io.nextInt(), m = io.nextInt();
    char[][] s = new char[n][];
    mask = new boolean[n][m][4];
    int[][][] time = new int[n][m][4];
    for (int i = 0; i < n; i++) {
      s[i] = io.next().toCharArray();
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '+') mask[i][j][0] = mask[i][j][1] = mask[i][j][2] = mask[i][j][3] = true;
        else if (s[i][j] == '-') mask[i][j][1] = mask[i][j][3] = true;
        else if (s[i][j] == '|') mask[i][j][0] = mask[i][j][2] = true;
        else if (s[i][j] == '^') mask[i][j][0] = true;
        else if (s[i][j] == '>') mask[i][j][1] = true;
        else if (s[i][j] == 'v') mask[i][j][2] = true;
        else if (s[i][j] == '<') mask[i][j][3] = true;
        else if (s[i][j] == 'U') mask[i][j][1] = mask[i][j][2] = mask[i][j][3] = true;
        else if (s[i][j] == 'R') mask[i][j][0] = mask[i][j][2] = mask[i][j][3] = true;
        else if (s[i][j] == 'D') mask[i][j][0] = mask[i][j][1] = mask[i][j][3] = true;
        else if (s[i][j] == 'L') mask[i][j][0] = mask[i][j][1] = mask[i][j][2] = true;
        time[i][j][0] = time[i][j][1] = time[i][j][2] = time[i][j][3] = MAX_TIME;
      }
    }
    int tx = io.nextInt() - 1, ty = io.nextInt() - 1;
    int mx = io.nextInt() - 1, my = io.nextInt() - 1;
    time[tx][ty][0] = 0;
    Queue<int[]> q = new LinkedList<>();
    q.add(new int[]{tx, ty, 0});
    while (!q.isEmpty()) {
      int[] u = q.poll();
      int x = u[0], y = u[1], t = u[2];
      if (x == mx && y == my) break;
      if (time[x][y][t] + 1 < time[x][y][(t+1)&3]) {
        time[x][y][(t+1)&3] = time[x][y][t] + 1;
        q.add(new int[]{x, y, (t+1)&3});
      }
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '*') continue;
        if (time[x][y][t] + 1 < time[nx][ny][t] && mask[x][y][(4-t+i)&3] && mask[nx][ny][(4-t+i+2)&3]) {
          time[nx][ny][t] = time[x][y][t] + 1;
          q.add(new int[]{nx, ny, t});
        }
      }
    }
    int res = MAX_TIME;
    for (int x : time[mx][my]) {
      res = Math.min(res, x);
    }
    io.println(res == MAX_TIME ? -1 : res);
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
