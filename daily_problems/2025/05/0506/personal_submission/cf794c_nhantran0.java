import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/794/C">C. Naming Company</a>
 * <p>Author: nhant
 * <p>2025-05-07 02:04:46 +0800
 * https://codeforces.com/problemset/submission/794/318672745, O(N)
 **/
public class C {
  static IO io;

  private static void solve() {
    int[] cnt1 = new int[26], cnt2 = new int[26];
    char[] s = io.next().toCharArray();
    int n = s.length;
    for (char c : s) {
      cnt1[c - 'a']++;
    }
    s = io.next().toCharArray();
    for (char c : s) {
      cnt2[c - 'a']++;
    }
    int skip1 = n / 2, skip2 = (n + 1) / 2; // length of chars to IGNORE
    for (int i = 0; i < 26; i++) {
      int d1 = Math.min(skip1, cnt1[25 - i]);
      skip1 -= d1;
      cnt1[25 - i] -= d1;
      int d2 = Math.min(skip2, cnt2[i]);
      skip2 -= d2;
      cnt2[i] -= d2;
    }
    int l1 = 0, r1 = 25, l2 = 0, r2 = 25;
    while (l1 <= r1 && cnt1[l1] == 0) l1++;
    while (l1 <= r1 && cnt1[r1] == 0) r1--;
    while (l2 <= r2 && cnt2[l2] == 0) l2++;
    while (l2 <= r2 && cnt2[r2] == 0) r2--;

    if (n == 1) {
      io.println((char) ('a' + l1));
      return;
    }
    char[] res = new char[n];
    for (int l = 0, r = n - 1; l <= r; ) {
      if ((n - (r - l + 1)) % 2 == 0) { // 1st player's turn
        if (l2 > r2 || l1 < r2) {
          res[l++] = (char) ('a' + l1);
          cnt1[l1]--;
          while (l1 <= r1 && cnt1[l1] == 0) {
            l1++;
          }
        } else {
          res[r--] = (char) ('a' + r1);
          cnt1[r1]--;
          while (l1 <= r1 && cnt1[r1] == 0) {
            r1--;
          }
        }
      } else {
        if (l1 > r1 || l1 < r2) {
          res[l++] = (char) ('a' + r2);
          cnt2[r2]--;
          while (l2 <= r2 && cnt2[r2] == 0) {
            r2--;
          }
        } else {
          res[r--] = (char) ('a' + l2);
          cnt2[l2]--;
          while (l2 <= r2 && cnt2[l2] == 0) {
            l2++;
          }
        }
      }
    }
    io.println(new String(res));
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
