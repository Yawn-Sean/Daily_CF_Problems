import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        // 做到第ez个数，选了vn个数的最大价值和
        long[][] dp = new long[n + 1][10];
        for (int ez = 0; ez <= n; ez++)
            Arrays.fill(dp[ez], -1);
        dp[0][0] = 0;
        int m = 0, c = 0;
        long d = 0, max1 = 0, max2 = 0, max3 = 0, max4 = 0, max5 = 0;
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(f.readLine());
            m = Integer.parseInt(st.nextToken());
            // 最大的，第二大的，第三大的，c2最大的，c3最大的
            // 如果每轮结束，可以选择保留3cost手牌到下个回合，就把这五个数每轮初始值做修改
            max1 = max2 = max3 = max4 = max5 = 0;
            for (int vn = 1; vn <= m; vn++) {
                st = new StringTokenizer(f.readLine());
                c = Integer.parseInt(st.nextToken());
                d = Long.parseLong(st.nextToken());
                if (c == 1) {
                    if (d >= max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = d;
                    } else if (d >= max2) {
                        max3 = max2;
                        max2 = d;
                    } else
                        max3 = Math.max(max3, d);
                } else if (c == 2)
                    max4 = Math.max(max4, d);
                else
                    max5 = Math.max(max5, d);
            }
            // 不选也可能为了更大的暴击
            for (int vn = 0; vn <= 9; vn++)
                dp[ez][vn] = dp[ez - 1][vn];
            for (int cc = 1; cc <= 3; cc++) {
                for (int vn = 0; vn <= 9; vn++) {
                    // 所有的情况都要转移
                    // 且vn需要 mod 10来转移
                    if (cc == 1) {
                        if (dp[ez - 1][vn] >= 0) {
                            // 转移1
                            if (max1 > 0)
                                dp[ez][(vn + 1) % 10] = Math.max(dp[ez][(vn + 1) % 10], dp[ez - 1][vn] + max1 * (1 + (vn == 9 ? 1 : 0)));
                        }
                    } else if (cc == 2) {
                        if (dp[ez - 1][vn] >= 0) {
                            // 转移1,1
                            if (max1 > 0 && max2 > 0)
                                dp[ez][(vn + 2) % 10] = Math.max(dp[ez][(vn + 2) % 10], dp[ez - 1][vn] + max1 * (1 + (vn >= 8 ? 1 : 0)) + max2);
                            // 转移2
                            if (max4 > 0)
                                dp[ez][(vn + 1) % 10] = Math.max(dp[ez][(vn + 1) % 10], dp[ez - 1][vn] + max4 * (1 + (vn >= 9 ? 1 : 0)));
                        }
                    } else if (cc == 3) {
                        if (dp[ez - 1][vn] >= 0) {
                            // 转移1,1,1
                            if (max1 > 0 && max2 > 0 && max3 > 0)
                                dp[ez][(vn + 3) % 10] = Math.max(dp[ez][(vn + 3) % 10], dp[ez - 1][vn] + max1 * (1 + (vn >= 7 ? 1 : 0)) + max2 + max3);
                            // 转移2,1
                            if (max1 > 0 && max4 > 0)
                                dp[ez][(vn + 2) % 10] = Math.max(dp[ez][(vn + 2) % 10], dp[ez - 1][vn] + Math.max(max1, max4) * (1 + (vn >= 8 ? 1 : 0)) + Math.min(max1, max4));
                            // 转移3
                            if (max5 > 0)
                                dp[ez][(vn + 1) % 10] = Math.max(dp[ez][(vn + 1) % 10], dp[ez - 1][vn] + max5 * (1 + (vn >= 9 ? 1 : 0)));
                        }
                    }
                }
            }
        }
        long res = 0;
        for (int ez = 0; ez <= 9; ez++)
            res = Math.max(res, dp[n][ez]);
        pw.println(res);
        pw.close();
        f.close();
    }

}
