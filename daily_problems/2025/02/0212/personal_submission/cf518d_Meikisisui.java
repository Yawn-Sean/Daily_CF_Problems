import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        double p = Double.parseDouble(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        // dp[i][j]为第i秒有j个人的概率
        double[][] dp = new double[t + 1][n + 1];
        dp[0][0] = 1;
        for (int ez = 1; ez <= t; ez++) {
            for (int vn = 0; vn <= n; vn++) {
                if (vn == n)
                    dp[ez][vn] += dp[ez - 1][vn];
                else
                    dp[ez][vn] += (1 - p) * dp[ez - 1][vn];
                if (vn > 0)
                    dp[ez][vn] += dp[ez - 1][vn - 1] * p;
            }
        }
        double res = 0;
        for (int ez = 1; ez <= n; ez++)
            res += ez * dp[t][ez];
        pw.print(res);
        pw.close();
        br.close();
    }

}
