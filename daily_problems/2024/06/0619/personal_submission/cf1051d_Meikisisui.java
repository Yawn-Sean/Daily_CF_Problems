import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Test2 {

    public static void main(String[] args) throws Exception {
        Test2 test = new Test2();
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int res = test.bicolorings(a, b);
        System.out.println(res);
    }

    private int MOD = 998244353;
    private long[][][] memo;

    private int bicolorings(int n, int k) {
        this.memo = new long[n][k][4];
        for (long[][] ez : memo) {
            for (long[] vn : ez)
                Arrays.fill(vn, -1);
        }
        memo[0][0][2] = memo[0][0][3] = 1;
        if (k > 1)
            memo[0][1][0] = memo[0][1][1] = 1;
        long res = (dfs(n - 1, k - 1, 0) + dfs(n - 1, k - 1, 1)
                + dfs(n - 1, k - 1, 2) + dfs(n - 1, k - 1, 3)) % MOD;
        return (int) res;
    }

    private long dfs(int n, int k, int status) {
        if (n < 0 || k < 0)
            return 0;
        if (-1 != memo[n][k][status])
            return memo[n][k][status];
        long res = 0;
        if (status == 0) {
            res += dfs(n - 1, k, 0);
            res += dfs(n - 1, k - 2, 1);
            res += dfs(n - 1, k - 1, 2);
            res += dfs(n - 1, k - 1, 3);
        }
        if (status == 1) {
            res += dfs(n - 1, k - 2, 0);
            res += dfs(n - 1, k, 1);
            res += dfs(n - 1, k - 1, 2);
            res += dfs(n - 1, k - 1, 3);
        }
        if (status == 2) {
            res += dfs(n - 1, k, 0);
            res += dfs(n - 1, k, 1);
            res += dfs(n - 1, k, 2);
            res += dfs(n - 1, k - 1, 3);
        }
        if (status == 3) {
            res += dfs(n - 1, k, 0);
            res += dfs(n - 1, k, 1);
            res += dfs(n - 1, k - 1, 2);
            res += dfs(n - 1, k, 3);
        }
        return memo[n][k][status] = res % MOD;
    }

}
