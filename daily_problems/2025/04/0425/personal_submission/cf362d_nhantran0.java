import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/contest/362/problem/D">D. Fools and Foolproof Roads</a>
 * <p>Author: nhant
 * <p>2025-04-26 00:06:51 +0800
 * <p>Submission: <a href="https://codeforces.com/contest/362/submission/317221598">Apr/26/2025 03:10UTC+8, 562 ms, 5400 KB</a>
 **/
public class D {
  static IO io;

  static int[] d;
  static long[] cl;
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
    final int L = (int)1e9;
    int n = io.ni(), m = io.ni(), p = io.ni(), q = io.ni();
    d = new int[n];
    cl = new long[n];
    Arrays.fill(d, -1);
    Arrays.fill(cl, 0);
    int[] sameReg = new int[2];
    sameReg[0] = sameReg[1] = -1;
    for (int i = 0; i < m; i++) {
      int u = io.ni() - 1, v = io.ni() - 1, l = io.ni();
      int pu = get(u), pv = get(v);
      if (unite(u, v)) {
        cl[get(u)] = cl[pu] + cl[pv] + l;
        if (sameReg[0] == -1) {
          sameReg[0] = u;
          sameReg[1] = v;
        }
      } else {
        cl[get(u)] += l;
      }
    }
    PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingLong(v -> cl[v]));
    for (int i = 0; i < n; i++) {
      if (d[i] < 0) {
        pq.offer(i);
      }
    }
    List<int[]> ne = new ArrayList<>();
    while (p > 0 && pq.size() > q) {
      int u = pq.poll(), v = pq.poll();
      unite(u, v);
      int pa = get(u);
      cl[pa] = cl[u] + cl[v] + Math.min(L, cl[u] + cl[v] + 1);
      pq.offer(pa);
      ne.add(new int[]{u, v});
      if (sameReg[0] == -1) {
        sameReg[0] = u;
        sameReg[1] = v;
      }
      p--;
    }
    if (pq.size() == q && p > 0 && sameReg[0] != -1) {
      for (; p > 0; p--) {
        ne.add(new int[]{sameReg[0], sameReg[1]});
      }
    }
    if (pq.size() == q && p == 0) {
      io.println("YES");
      for (int[] e : ne) {
        io.printf("%d %d\n", e[0] + 1, e[1] + 1);
      }
    } else {
      io.println("NO");
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
