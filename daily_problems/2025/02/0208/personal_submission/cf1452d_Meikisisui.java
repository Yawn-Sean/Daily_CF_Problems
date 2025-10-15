import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    private static int mod = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] dp = new int[n + 5], odd = new int[n + 5], even = new int[n + 5];
        int ez = 2;
        dp[0] = dp[1] = 1;
        odd[1] = 1;
        even[0] = even[1] = 1;
        for (; ez <= n; ez++) {
            dp[ez] = (dp[ez] + dp[ez - 1]) % mod;
            if (ez >= 3) {
                if (ez % 2 == 1)
                    dp[ez] = (dp[ez] + even[ez - 3]) % mod;
                else
                    dp[ez] = (dp[ez] + odd[ez - 3]) % mod;
            }
            // 更新奇偶前缀和
            odd[ez] = odd[ez - 1];
            even[ez] = even[ez - 1];
            if (ez % 2 == 1) {
                odd[ez] += dp[ez];
                odd[ez] %= mod;
            } else {
                even[ez] += dp[ez];
                even[ez] %= mod;
            }
        }
        long tmp = 1;
        for (ez = 1; ez <= n; ez++)
            tmp = tmp * 2 % mod;
        long res = quickPow(tmp, mod - 2, mod) % mod * dp[n] % mod;
        pw.print(res);
        pw.close();
        f.close();
    }

    public static long quickPow(long a, int b, int p) {
        // 防止p=1，否则返回0
        long res = 1 % p;
        while (b > 0) {
            // b最后一位是否是1
            if ((b & 1) == 1)
                res = res * a % p;
            a = (int) ((long) a * a % p);
            // 删除b最后一位
            b >>= 1;
        }
        return (int) res;
    }

}
