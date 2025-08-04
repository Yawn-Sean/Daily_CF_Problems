import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] sum = new long[n + 1];
        for (int ez = 1; ez <= n; ez++)
            sum[ez] = sum[ez - 1] + Integer.parseInt(st.nextToken());
        // dp1[ez]记录前缀最大值
        long[] dp1 = new long[n + 1], dp2 = new long[n + 1];
        long max = Integer.MIN_VALUE / 10;
        for (int ez = 1; ez <= n; ez++) {
            max = Math.max(max, -2 * sum[ez]);
            dp1[ez] = sum[ez] + max;
        }
        // dp2[ez]记录后缀最大值
        max = Integer.MIN_VALUE / 10;
        for (int ez = n; ez > 0; ez--) {
            max = Math.max(max, -2 * (sum[n] - sum[ez - 1]));
            dp2[ez] = sum[n] - sum[ez - 1] + max;
        }
        long res = sum[n];
        for (int ez = 0; ez <= n; ez++) {
            if (ez == n)
                res = Math.max(res, dp1[ez]);
            else
                res = Math.max(res, dp1[ez] + dp2[ez + 1]);
        }
        pw.println(res);
        pw.close();
    }

}
