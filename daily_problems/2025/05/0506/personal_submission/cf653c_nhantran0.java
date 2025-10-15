import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/653/C">C. Bear and Up-Down</a>
 * <p>Author: nhant
 * <p>2025-05-07 06:05:33 +0800
 **/
public class C {
  static IO io;

  private static void swap(int[] t, int i, int j) {
    int v = t[i];
    t[i] = t[j];
    t[j] = v;
  }
  private static boolean nice(int[] t, int i) {
    return (i % 2 == 0 && t[i] < t[i + 1]) || (i % 2 == 1 && t[i] > t[i + 1]);
  }
  private static boolean nbNice(int[] t, int i) {
    return (i == 0 || nice(t, i - 1)) && (i == t.length - 1 || nice(t, i));
  }
  private static int swapCheckRevert(int[] t, int i, int j) {
    swap(t, i, j);
    int res = nbNice(t, i) && nbNice(t, j) ? 1 : 0;
    swap(t, i, j);
    return res;
  }
  private static int swapCheckRevertPrint(int[] t, int i, int j) {
    swap(t, i, j);
    int res = nbNice(t, i) && nbNice(t, j) ? 1 : 0;
    if (res == 1) {
      io.printf("%d,%d: %s\n", i, j, Arrays.toString(t));
    }
    swap(t, i, j);
    return res;
  }

  private static void solve() {
    int n = io.ni();
    int[] t = new int[n];
    List<Integer> nn = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      t[i] = io.ni();
      if (i > 0 && nn.size() < 5 && !nice(t, i - 1)) {
        nn.add(i - 1);
      }
    }
    int res = 0;
    if (nn.size() == 4) {
      int i0 = nn.get(0), i1 = nn.get(1), i2 = nn.get(2), i3 = nn.get(3);
      if (i0 + 1 == i1 && i2 + 1 == i3) {
        res += swapCheckRevert(t, i1, i3);
      }
    } else if (nn.size() == 3) {
      int i0 = nn.get(0), i1 = nn.get(1), i2 = nn.get(2);
      if (i0 + 1 == i1 || i1 + 1 == i2) {
        if (i1 + 1 == i2) {
          res += swapCheckRevert(t, i0, i2);
        }
        res += swapCheckRevert(t, i1, i2);
        if (i0 + 1 == i1) {
          res += swapCheckRevert(t, i1, i2 + 1);
        }
      }
    } else if (nn.size() == 2) {
      int i0 = nn.get(0), i1 = nn.get(1);
      if (i0 + 1 == i1) {
        for (int i = 0; i < n; i++) {
          if (i != i1) {
            res += swapCheckRevert(t, i, i1);
          }
        }
      } else {
        res += swapCheckRevert(t, i0, i1);
        res += swapCheckRevert(t, i0, i1 + 1);
        res += swapCheckRevert(t, i0 + 1, i1);
        res += swapCheckRevert(t, i0 + 1, i1 + 1);
      }
    } else if (nn.size() == 1) {
      int i0 = nn.get(0);
      for (int i = 0; i < n; i++) {
        if (i != i0) {
          res += swapCheckRevert(t, i, i0);
        }
        if (i != i0 && i != i0 + 1) { // exclude (i0,i0+1) pair which was counted above
          res += swapCheckRevert(t, i, i0 + 1);
        }
      }
    }
    io.println(res);
  }

  private static void bruteforce(int[] t) {
    io.printf("----%s\n", Arrays.toString(t));
    for (int i = 0; i < t.length - 1; i++) {
      for (int j = i + 1; j < t.length; j++) {
        swap(t, i, j);
        boolean good = true;
        for (int k = 0; k < t.length - 1; k++) {
          if (!nice(t, k)) {
            good = false;
            break;
          }
        }
        if (good) {
          io.printf("%d,%d %s\n", i, j, Arrays.toString(t));
        }
        swap(t, i, j);
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

    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
