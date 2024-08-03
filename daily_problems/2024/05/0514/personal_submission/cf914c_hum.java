public class TravellingSalesmanAndSpecialNumbers {
  int[] ops = new int[1001];
  int mod = (int) (1e9 + 7);
  long[][] memo = new long[1001][1001];

  {
    for (int i = 0; i < 1001; i++) {
      Arrays.fill(memo[i], -1);
    }
  }

  int[] num;
  int len;
  int k;

  public void solve(int testNumber, InputReader in, OutputWriter out) {
    String n = in.nextString();
    len = n.length();
    k = in.nextInt();
    if (k == 0) {
      out.println(1);
      return;
    }
    if (k == 1) {
      out.println(len - 1);
      return;
    }

    for (int i = 2; i < 1001; i++) {
      ops[i] = ops[Integer.bitCount(i)] + 1;
    }
    num = new int[len];
    for (int i = 0; i < len; i++) {
      num[i] = n.charAt(i) - '0';
    }

    out.println(dfs(0, 0, true, true));
  }


  long dfs(int i, int st, boolean limit, boolean lead) {
    if (i == len) {
      return ops[st] == k - 1 ? 1 : 0;
    }
    if (!limit && !lead && memo[i][st] != -1) {
      return memo[i][st];
    }

    long res = 0;
    if (lead) {
      res = dfs(i + 1, st, false, true);
    }

    int up = limit ? num[i] : 1;
    int low = lead ? 1 : 0;

    for (int j = low; j <= up; j++) {
      res += dfs(i + 1, st + (1 == j ? 1 : 0), limit && j == up, false);
      res %= mod;
    }
    if (!limit && !lead) {
      memo[i][st] = res;
    }
    return res;
  }
}