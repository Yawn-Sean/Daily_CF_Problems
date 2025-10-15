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
        String s = st.nextToken();
        int len = s.length();
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][][] dp = new int[len + 1][n + 1][2];
        for (int ez = 0; ez <= len; ez++) {
            for (int vn = 0; vn <= n; vn++)
                dp[ez][vn][0] = dp[ez][vn][1] = Integer.MIN_VALUE / 10;
        }
        dp[0][0][0] = 0; // 正
        dp[0][0][1] = 0; // 负
        for (int ez = 1; ez <= len; ez++) {
            char current = s.charAt(ez - 1);
            for (int vn = 0; vn <= n; vn++) {
                for (int status = 0; status <= vn; status++) {
                    if (current == 'F') {
                        if (status % 2 == 1) {
                            dp[ez][vn][0] = Math.max(dp[ez][vn][0], dp[ez - 1][vn - status][1]);
                            dp[ez][vn][1] = Math.max(dp[ez][vn][1], dp[ez - 1][vn - status][0]);
                        } else {
                            dp[ez][vn][0] = Math.max(dp[ez][vn][0], dp[ez - 1][vn - status][0] + 1);
                            dp[ez][vn][1] = Math.max(dp[ez][vn][1], dp[ez - 1][vn - status][1] - 1);
                        }
                    } else {
                        if (status % 2 == 1) {
                            dp[ez][vn][0] = Math.max(dp[ez][vn][0], dp[ez - 1][vn - status][0] + 1);
                            dp[ez][vn][1] = Math.max(dp[ez][vn][1], dp[ez - 1][vn - status][1] - 1);
                        } else {
                            dp[ez][vn][0] = Math.max(dp[ez][vn][0], dp[ez - 1][vn - status][1]);
                            dp[ez][vn][1] = Math.max(dp[ez][vn][1], dp[ez - 1][vn - status][0]);
                        }
                    }
                }
            }
        }
        pw.println(Math.max(dp[len][n][0], dp[len][n][1]));
        pw.close();
        br.close();
    }

}
