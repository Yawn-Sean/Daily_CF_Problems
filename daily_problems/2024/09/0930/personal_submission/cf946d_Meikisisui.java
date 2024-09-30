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
        int days = Integer.parseInt(st.nextToken());
        int workHourPerDay = Integer.parseInt(st.nextToken());
        int limit = Integer.parseInt(st.nextToken());
        char[][] timeTable = new char[days][];
        for (int ez = 0; ez < days; ez++) {
            st = new StringTokenizer(f.readLine());
            timeTable[ez] = st.nextToken().toCharArray();
        }
        int[][] dp = new int[days + 1][];
        dp[0] = new int[limit + 1];
        for (int ez = 1; ez <= days; ez++) {
            dp[ez] = new int[limit + 1];
            int[] help = new int[workHourPerDay];
            int cnt = 0;
            for (int vn = 0; vn < workHourPerDay; vn++) {
                if (timeTable[ez - 1][vn] == '1')
                    help[cnt++] = vn;
            }
            int[] minTime = new int[cnt + 1];
            for (int vn = 0; vn < cnt; vn++) {
                minTime[vn] = Integer.MAX_VALUE;
                for (int k = 0; k < vn + 1; k++)
                    minTime[vn] = Math.min(minTime[vn], help[k + (cnt - vn) - 1] - help[k] + 1);
            }
            for (int vn = 0; vn <= limit; vn++) {
                dp[ez][vn] = Integer.MAX_VALUE;
                for (int k = 0; k <= Math.min(vn, cnt); k++)
                    dp[ez][vn] = Math.min(dp[ez][vn], dp[ez - 1][vn - k] + minTime[k]);
            }
        }
        pw.println(dp[days][limit]);
        pw.close();
        f.close();
    }

}
