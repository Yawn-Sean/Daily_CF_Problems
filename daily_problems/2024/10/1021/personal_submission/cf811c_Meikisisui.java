import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int MAX = 5001;
        int[] arr = new int[MAX];
        // 前i个人的最大价值
        int[] dp = new int[MAX];
        int[] minn = new int[MAX];
        int[] maxn = new int[MAX];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
            if (minn[arr[ez]] == 0)
                minn[arr[ez]] = ez;
            maxn[arr[ez]] = ez;
        }
        for (int ez = 1; ez <= n; ez++) {
            dp[ez] = dp[ez - 1];
            int tmp = 0;
            int pos = minn[arr[ez]];
            for (int vn = ez; vn > 0; vn--) {
                int now = arr[vn];
                // 当前区间该数字出现最早的位置
                pos = Math.min(minn[now], pos);
                if (maxn[now] > ez)
                    break;
                if (minn[now] == vn)
                    // 最小位置进行异或
                    tmp ^= now;
                if (pos == vn)
                    // 遍历过的所有数字的最小位置==vn时才更新dp的最大值
                    dp[ez] = Math.max(dp[ez], dp[vn - 1] + tmp);
            }
        }
        pw.println(dp[n]);
        pw.close();
        f.close();
    }

}
