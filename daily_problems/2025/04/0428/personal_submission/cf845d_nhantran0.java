import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/845/D">D. Driving Test</a>
 * <p>Author: nhant
 * <p>2025-04-28 19:35:26 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/845/317574389">Apr/28/2025 21:07UTC+8, 343 ms, 1800 KB</a>
 **/
public class D {
  static IO io;

  private static void solve() {
    int n = io.ni();
    int res = 0;
    Stack<Integer> spdLim = new Stack<>();
    int spd = 0, noOverTakeCnt = 0;
    for (int i = 0; i < n; i++) {
      int t = io.ni();
      if (t == 1) {
        spd = io.ni();
        while (!spdLim.isEmpty() && spdLim.peek() < spd) {
          spdLim.pop();
          res++;
        }
      } else if (t == 2) {
        if (noOverTakeCnt > 0) {
          res += noOverTakeCnt;
          noOverTakeCnt = 0;
        }
      } else if (t == 3) {
        int sl = io.ni();
        if (sl < spd) {
          res++;
        } else {
          spdLim.push(sl);
        }
      } else if (t == 4) {
        noOverTakeCnt = 0;
      } else if (t == 5) {
        while (!spdLim.isEmpty()) {
          spdLim.pop();
        }
      } else if (t == 6) {
        noOverTakeCnt++;
      }
    }
    io.println(res);
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
