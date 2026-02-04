import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        int sum = 0;
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
            sum += arr[ez];
        }
        if ((sum & 1) == 1) {
            pw.println(-1);
            pw.close();
            return;
        }

        sum /= 2;
        int[] dp = new int[sum + 1];
        Arrays.fill(dp, Integer.MIN_VALUE / 10);
        dp[0] = -1;
        for (int ez = 0; ez < n; ez++) {
            int now = arr[ez];
            for (int vn = sum; vn >= now; vn--) {
                if (dp[vn - now] != Integer.MIN_VALUE / 10 && dp[vn] == Integer.MIN_VALUE / 10)
                    dp[vn] = ez;
            }
        }
        if (dp[sum] == Integer.MIN_VALUE / 10) {
            pw.println(-1);
            pw.close();
            return;
        }

        int[] vis = new int[n];
        while (sum > 0) {
            int ez = dp[sum];
            vis[ez] = 1;
            sum -= arr[ez];
        }
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        for (int ez = 0; ez < n; ez++) {
            if (vis[ez] == 1)
                list1.add(arr[ez]);
            else
                list2.add(arr[ez]);
        }
        int sum1 = 0, sum2 = 0, p1 = 0, p2 = 0;
        String res = "";
        while (p1 < list1.size() || p2 < list2.size()) {
            if (sum1 <= sum2) {
                int now = list1.get(p1++);
                res += (now + " ");
                sum1 += now;
            } else {
                int now = list2.get(p2++);
                res += (now + " ");
                sum2 += now;
            }
        }
        pw.println(res);
        pw.close();
    }

}
