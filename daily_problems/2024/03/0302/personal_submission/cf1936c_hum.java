import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    CPokmonArena solver = new CPokmonArena();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class CPokmonArena {
    int n;
    int m;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      m = in.nextInt();
      int[] c = in.nextInt(n);
      int[][] a = new int[n][m];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt(m);
      }
      Graph graph = new Graph(n * m + n, 5 * (n * m + n), true);

      for (int j = 0; j < m; j++) {
        List<int[]> tmp = new ArrayList<>();
        for (int i = 1; i < n; i++) {
          tmp.add(new int[]{a[i][j], i});
        }
        tmp.sort((x, y) -> y[0] - x[0]);
        graph.add(0, p(tmp.get(0)[1], j, 0), Math.max(0, a[0][j] - tmp.get(0)[0]));
        graph.add(p(tmp.get(0)[1], j, 0), p2(tmp.get(0)[1]), c[tmp.get(0)[1]]);

        graph.add(p2(tmp.get(0)[1]), p(tmp.get(0)[1], j, 0), 0);


        for (int i = 0; i < n - 2; i++) {
          int[] x = tmp.get(i);
          int[] y = tmp.get(i + 1);
          graph.add(0, p(y[1], j, 0), Math.max(0, a[0][j] - y[0]));

          graph.add(p(x[1], j, 0), p(y[1], j, 0), x[0] - y[0]);
          graph.add(p(y[1], j, 0), p(x[1], j, 0), 0);

          graph.add(p(y[1], j, 0), p2(y[1]), c[y[1]]);
          graph.add(p2(y[1]), p(y[1], j, 0), 0);
        }
      }

      Dijkstra dijkstra = new Dijkstra();
      long[] res = dijkstra.dijkstra(graph, 0);
      out.println(res[p2(n - 1)]);

    }

    private int p(int i, int j, int f) {
      return (i - (1 - f)) * m + (j + 1);
    }

    private int p2(int i) {
      return n * m + i;
    }

    class Dijkstra {
      public long inf = (long) 1e17;

      public long[] dijkstra(Graph graph, int s) {
        long[] dist = new long[graph.N];
        boolean[] vis = new boolean[graph.N];
        Arrays.fill(dist, inf);
        dist[s] = 0;
        PriorityQueue<long[]> priorityQueue = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        priorityQueue.add(new long[]{0, s});
        while (!priorityQueue.isEmpty()) {
          long[] poll = priorityQueue.poll();
          long d = poll[0];
          int u = (int) poll[1];
          if (vis[u]) {
            continue;
          }
          vis[u] = true;
          for (int i = graph.h[u]; i != -1; i = graph.ne[i]) {
            int j = graph.e[i];
            if (dist[j] > d + graph.w[i]) {
              dist[j] = d + graph.w[i];
              priorityQueue.add(new long[]{dist[j], j});
            }
          }
        }
        return dist;
      }

    }

  }

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (numChars == -1) {
        throw new UnknownError();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new UnknownError();
        }
        if (numChars <= 0) {
          return -1;
        }
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new UnknownError();
        }
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public int[] nextInt(int n) {
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = nextInt();
      }
      return a;
    }

    public String nextString() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        if (Character.isValidCodePoint(c)) {
          res.appendCodePoint(c);
        }
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next() {
      return nextString();
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);

    }

  }

  static class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void close() {
      writer.close();
    }

    public void println(long i) {
      writer.println(i);
    }

  }

  static class Graph {
    public int N;
    public int M;
    public int[] h;
    public int[] e;
    public int[] ne;
    public int[] w;
    int idx;
    int n;
    int m;
    boolean flag;
    public int[] fe;

    public Graph(int n, int m) {
      this(n, m, false);
    }

    public Graph(int n, int m, boolean f) {
      this.n = n;
      this.m = m;
      flag = f;
      N = n + 5;
      M = flag ? m + 5 : m * 2 + 5;

      h = new int[N];
      e = new int[M];
      ne = new int[M];
      w = new int[M];
      idx = 0;
      Arrays.fill(h, -1);

      fe = new int[M];
    }

    public void add(int a, int b, int c) {
      add0(a, b, c);
      if (!flag) {
        add0(b, a, c);
      }
    }

    private void add0(int a, int b, int c) {
      fe[idx] = a;
      e[idx] = b;
      w[idx] = c;
      ne[idx] = h[a];
      h[a] = idx++;
    }

  }
}

