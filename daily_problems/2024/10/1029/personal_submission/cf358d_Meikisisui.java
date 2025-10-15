import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] rabbits = new int[3][n];
        for (int ez = 0; ez < 3; ez++) {
            st = new StringTokenizer(f.readLine());
            for (int vn = 0; vn < n; vn++)
                rabbits[ez][vn] = Integer.parseInt(st.nextToken());
        }
        // 0下一个没吃,到此的最大代价
        // 1下一个吃了,
        int[][] dp = new int[2][n];
        dp[0][0] = rabbits[0][0];
        dp[1][0] = rabbits[1][0];
        for (int ez = 1; ez < n; ez++) {
            dp[0][ez] = dp[1][ez] = Integer.MIN_VALUE / 2;
            dp[0][ez] = Math.max(dp[0][ez - 1] + rabbits[1][ez], dp[1][ez - 1] + rabbits[0][ez]);
            dp[1][ez] = Math.max(dp[0][ez - 1] + rabbits[2][ez], dp[1][ez - 1] + rabbits[1][ez]);
//            System.out.println("0," + ez + ":" + dp[0][ez]);
//            System.out.println("1," + ez + ":" + dp[1][ez]);
        }
        pw.println(dp[0][n - 1]);
        pw.close();
        f.close();
    }

}
