import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        int[] an = new int[n];
        int[] bn = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            an[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            bn[ez] = Integer.parseInt(st.nextToken());
        Integer[] order = new Integer[n];
        for (int ez = 0; ez < n; ez++)
            order[ez] = ez;
        Arrays.sort(order, (ez, vn) -> Integer.compare(bn[vn], bn[ez]));
        long[] dp = new long[n + 1];
        Arrays.fill(dp, Long.MAX_VALUE / 10);
        dp[0] = 0;
        for (int ez = 0; ez < n; ez++) {
            int now = order[ez];
            int x = an[now], y = bn[now];
            for (int vn = ez; vn >= 0; vn--)
                dp[vn + 1] = Math.min(dp[vn + 1], x + (long) vn * y + dp[vn]);
        }
        for (int ez = n; ez >= 0; ez--) {
            if (dp[ez] <= b) {
                pw.println(ez + " " + dp[ez]);
                break;
            }
        }
        pw.close();
    }

}
