import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/727/D">D. T-shirts Distribution</a>
 * <p>Author: nhant
 * <p>2025-04-09 00:30:20 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/727/314663507">Apr/09/2025 01:50UTC+8</a>
 * Greedy works because the 2 sizes to choose 1 from are next to each other.
 **/
public class D {
  static IO io;

  private static final String[] sizes = new String[]{"S", "M", "L", "XL", "XXL", "XXXL"};

  private static int nameToIdx(String s) {
    return switch (s) {
      case "S" -> 0;
      case "M" -> 1;
      case "L" -> 2;
      case "XL" -> 3;
      case "XXL" -> 4;
      case "XXXL" -> 5;
      default -> -1;
    };
  }

  private static void solve() {
    int[] a = new int[6];
    for (int i = 0; i < a.length; i++) {
      a[i] = io.nextInt();
    }
    int n = io.nextInt();
    List<int[]> want = new ArrayList<>(n);
    Integer[] ord = new Integer[n];
    int[] res = new int[n];
    boolean yes = true;
    for (int i = 0; i < n; i++) {
      String[] p = io.next().split(",");
      int[] b = new int[p.length];
      for (int j = 0; j < p.length; j++) {
        b[j] = nameToIdx(p[j]);
      }
      if (b.length == 1) {
        a[b[0]]--;
        if (a[b[0]] < 0) yes = false;
        ord[i] = -1;
        res[i] = b[0];
      } else {
        ord[i] = i;
      }
      want.add(b);
    }
    if (yes) {
      Arrays.sort(ord, (i, j) -> i != -1 && j != -1 ? (want.get(i)[0] - want.get(j)[0]) : (j == -1 ? -1 : 1));
      for (int i = 0; i < n && ord[i] != -1; i++) {
        int u = want.get(ord[i])[0], v = want.get(ord[i])[1];
        if (a[u] > 0) {
          res[ord[i]] = u;
          a[u]--;
        } else if (a[v] > 0) {
          res[ord[i]] = v;
          a[v]--;
        } else {
          yes = false;
          break;
        }
      }
    }
    io.println(yes ? "YES" : "NO");
    if (yes) {
      for (int i : res) {
        io.println(sizes[i]);
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
