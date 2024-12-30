//参考题解https://www.luogu.com.cn/article/cn22i9zm

import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class c914 {
    private static final int MOD = 1000000007;
    private static final int N = 1005;
    private static String s;
    private static long k;
    private static long[] num = new long[N];
    private static long[][] dp = new long[N][N];
    private static long[] f = new long[N];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        k = scanner.nextLong();
        scanner.close();

        // 初始化dp数组
        for (long[] row : dp) {
            Arrays.fill(row, -1);
        }

        int len = s.length();
        for (int i = 0; i < len; i++) {
            num[len - i] = s.charAt(i) - '0';
        }

        if (k == 0) {
            System.out.println(1);
            return;
        }

        // 预处理1000以内需要操作的次数
        for (int i = 1; i <= 1000; i++) {
            f[i] = getCnt(i);
        }

        long ans = DFS(len, 0, true, true);
        if (k == 1) ans--;
        System.out.println(ans);
    }

    private static int getBit(int x) {
        int ans = 0;
        while (x != 0) {
            if ((x & 1) != 0) ans++;
            x >>= 1;
        }
        return ans;
    }

    private static int getCnt(int x) {
        if (x == 1) return 0;
        return getCnt(getBit(x)) + 1;
    }

    private static long DFS(int pos, int sum, boolean flag, boolean zero) {
        if (pos == 0) {
            return (!zero && f[sum] + 1 == k) ? 1 : 0;
        }
        if (!zero && !flag && dp[pos][sum] != -1) {
            return dp[pos][sum];
        }

        long cnt = 0;
        long maxNum = flag ? num[pos] : 1;

        for (int i = 0; i <= maxNum; i++) {
            cnt += DFS(pos - 1, sum + (i == 1 ? 1 : 0), flag && (i == maxNum), zero && (i == 0));
            cnt %= MOD;
        }

        if (!zero && !flag) {
            dp[pos][sum] = cnt;
        }

        return cnt;
    }
}
