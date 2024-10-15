public class Main {

    // https://codeforces.com/problemset/problem/1082/B
    // 贪心：枚举S 求下S左右两边连续G的个数
    public static void solve() throws IOException {
        int n = in.nextInt();
        char[] s = in.nextLine().toCharArray();
        int gcnt = 0, scnt = 0;
        for (char c : s) {
            if (c == 'G') gcnt++;
            else scnt++;
        }
        if (scnt == 0) {
            out.println(gcnt);
            return;
        }
        if (gcnt == 0) {
            out.println(0);
            return;
        }
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = s[0] == 'G' ? 1 : 0;
        int cnt = left[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == 'S') cnt = 0;
            else left[i] = ++cnt;
        }
        right[n-1] = s[n-1] == 'G' ? 1 : 0;
        cnt = right[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'S') cnt = 0;
            else right[i] = ++cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'S') {
                int c1 = i - 1 >= 0 ? left[i-1] : 0;
                int c2 = i + 1 < n ? right[i+1] : 0;
                boolean flag = c1 + c2 == gcnt;
                ans = Math.max(ans, c1 + c2 + (flag ? 0 : 1));
            }
        }
        out.println(ans);
    }

    static boolean MULTI_CASE = false;

    public static void main(String[] args) throws Exception {
        int T = MULTI_CASE ? in.nextInt() : 1;
        while (T-- > 0) {
            solve();
        }
        out.close();
    }
}
