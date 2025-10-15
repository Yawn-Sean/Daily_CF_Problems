import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/386/D">D. Game with Points</a>
 * <p>Author: nhant
 * <p>2025-04-05 01:25:05 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/386/313964819">Apr/05/2025 03:03UTC+8</a>
 **/
public class D {
  static IO io;

  private static void setVisited(int x, int y, int z, boolean[][][] visited) {
    visited[x][y][z] = visited[x][z][y]
        = visited[y][x][z] = visited[y][z][x]
        = visited[z][x][y] = visited[z][y][x] = true;
  }

  private static void solve() {
    final int A = 26;
    int n = io.nextInt();
    int x = io.nextInt() - 1;
    int y = io.nextInt() - 1;
    int z = io.nextInt() - 1;
    char[][] colors = new char[n][];
    List<List<List<Integer>>> adj = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
      List<List<Integer>> next = new ArrayList<>(A);
      for (int k = 0; k < A; k++) next.add(new ArrayList<>());
      adj.add(next);
    }
    for (int i = 0; i < n; i++) {
      colors[i] = io.next().toCharArray();
      for (int j = i; j < n; j++) {
        if (colors[i][j] != '*') {
          int c = colors[i][j] - 'a';
          adj.get(i).get(c).add(j);
          adj.get(j).get(c).add(i);
        }
      }
    }
    Queue<Pos> q = new ArrayDeque<>();
    boolean[][][] visited = new boolean[n][n][n];
    q.add(new Pos(x, y, z, null));
    setVisited(x, y, z, visited);
    Pos target = new Pos(0, 1, 2, null);
    Pos end = null;
    while (!q.isEmpty() && end == null) {
      for (int k = q.size(); k > 0; k--) {
        Pos u = q.poll();
        if (u.match(target)) {
          end = u;
          break;
        }
        List<Integer> nb = adj.get(u.x).get(colors[u.y][u.z] - 'a');
        for (int v : nb) {
          if (v != u.y && v != u.z && !visited[v][u.y][u.z]) {
            setVisited(v, u.y, u.z, visited);
            q.add(new Pos(v, u.y, u.z, u));
          }
        }
        nb = adj.get(u.y).get(colors[u.x][u.z] - 'a');
        for (int v : nb) {
          if (v != u.x && v != u.z && !visited[u.x][v][u.z]) {
            setVisited(u.x, v, u.z, visited);
            q.add(new Pos(u.x, v, u.z, u));
          }
        }
        nb = adj.get(u.z).get(colors[u.x][u.y] - 'a');
        for (int v : nb) {
          if (v != u.x && v != u.y && !visited[u.x][u.y][v]) {
            setVisited(u.x, u.y, v, visited);
            q.add(new Pos(u.x, u.y, v, u));
          }
        }
      }
    }
    if (end == null) {
      io.println(-1);
      return;
    }
    List<int[]> path = new ArrayList<>();
    Pos cur = end;
    while (cur.prev != null) {
      Pos prev = cur.prev;
      if (cur.x != prev.x) {
        path.add(new int[]{prev.x, cur.x});
      } else if (cur.y != prev.y) {
        path.add(new int[]{prev.y, cur.y});
      } else {
        path.add(new int[]{prev.z, cur.z});
      }
      cur = prev;
    }
    io.println(path.size());
    for (int i = path.size() - 1; i >= 0; i--) {
      io.printf("%d %d\n", path.get(i)[0] + 1, path.get(i)[1] + 1);
    }
  }

  static class Pos {
    int x, y, z;
    Pos prev;

    public Pos(int x, int y, int z, Pos prev) {
      this.x = x;
      this.y = y;
      this.z = z;
      this.prev = prev;
    }

    boolean match(Pos o) {
      return (x == o.x && y == o.y && z == o.z) || (x == o.x && z == o.y && y == o.z)
          || (y == o.x && x == o.y && z == o.z) || (y == o.x && z == o.y && x == o.z)
          || (z == o.x && x == o.y && y == o.z) || (z == o.x && y == o.y && x == o.z);
    }

    @Override
    public String toString() {
      return "Pos{" +
          "x=" + x +
          ", y=" + y +
          ", z=" + z +
          '}';
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
