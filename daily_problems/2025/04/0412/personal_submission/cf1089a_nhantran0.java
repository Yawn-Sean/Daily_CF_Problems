import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1089/A">A. Alice the Fan</a>
 * <p>Author: nhant
 * <p>2025-04-13 02:09:49 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/1089/315221675">Apr/13/2025 07:14UTC+8</a>
 **/
public class A {
  static IO io;

  static final int S = 3;
  static final int U = 5;
  static final int A = 200;
  static boolean[][][][] f = new boolean[S + 1][S + 1][A + 1][A + 1];
  static int[][][][] prev = new int[S + 1][S + 1][A + 1][A + 1];

  private static void solve() {
    int a = io.nextInt();
    int b = io.nextInt();
    int s = -1, t = -1;
    for (int i = S; i >= 0 && s == -1; i--) {
      for (int j = 0; j <= S; j++) {
        if ((i == S || j == S) && f[i][j][a][b]) {
          s = i;
          t = j;
          break;
        }
      }
    }
    if (s == -1) {
      System.out.println("Impossible");
      return;
    }
    List<int[]> path = new ArrayList<>();
    int curS = s, curT = t, curA = a, curB = b;
    while (prev[curS][curT][curA][curB] != -1) {
      int last = prev[curS][curT][curA][curB];
      int prevB = last % (A + 1);
      last /= (A + 1);
      int prevA = last % (A + 1);
      last /= (A + 1);
      int prevT = last % (S + 1);
      int prevS = last / (S + 1);
      path.add(new int[]{curA - prevA, curB - prevB});
      curS = prevS;
      curT = prevT;
      curA = prevA;
      curB = prevB;
    }
    System.out.printf("%d:%d\n", s, t);
    for (int i = path.size() - 1; i >= 0; i--) {
      int[] cur = path.get(i);
      System.out.printf("%d:%d ", cur[0], cur[1]);
    }
    System.out.println();
  }

  public static void main(String[] args) {
    try {
      io = new IO();
      f[0][0][0][0] = true;
      prev[0][0][0][0] = -1;
      for (int s = 0; s <= S; s++) {
        for (int t = 0; t <= S; t++) {
          if (s == 0 && t == 0 || s == S && t == S) continue;
          int k = s + t < U ? 25 : 15;
          for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= A; b++) {
              int last = -1;
              if (t > 0 && s < S) { // B wins this set AND A hasn't won the match
                int v = (s * (S + 1) + t - 1) * (A + 1);
                for (int y = k, x = 0; b - y >= 0 && a - x >= 0 && x <= y - 2; x++) {
                  f[s][t][a][b] = f[s][t][a][b] || f[s][t - 1][a - x][b - y];
                  if (f[s][t - 1][a - x][b - y]) {
                    last = (v + a - x) * (A + 1) + b - y;
                  }
                }
                for (int y = k + 1, x = y - 2; b - y >= 0 && a - x >= 0; y++, x = y - 2) {
                  f[s][t][a][b] = f[s][t][a][b] || f[s][t - 1][a - x][b - y];
                  if (f[s][t - 1][a - x][b - y]) {
                    last = (v + a - x) * (A + 1) + b - y;
                  }
                }
              }
              if (s > 0 && t < S) { // A wins this set AND B hasn't won the match
                int v = ((s - 1) * (S + 1) + t) * (A + 1);
                for (int x = k, y = 0; a - x >= 0 && b - y >= 0 && x - 2 >= y; y++) {
                  f[s][t][a][b] = f[s][t][a][b] || f[s - 1][t][a - x][b - y];
                  if (f[s - 1][t][a - x][b - y]) {
                    last = (v + a - x) * (A + 1) + b - y;
                  }
                }
                for (int x = k + 1, y = x - 2; a - x >= 0 && b - y >= 0; x++, y = x - 2) {
                  f[s][t][a][b] = f[s][t][a][b] || f[s - 1][t][a - x][b - y];
                  if (f[s - 1][t][a - x][b - y]) {
                    last = (v + a - x) * (A + 1) + b - y;
                  }
                }
              }
              if (last != -1) {
                prev[s][t][a][b] = last;
              }
            }
          }
        }
      }
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
