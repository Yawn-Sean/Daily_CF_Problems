import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test6 {

    private static int[] a;
    private static int[] dp;
    private static Pair[] pair;
    private static int n;

    private static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        a = new int[n];
        dp = new int[n];
        pair = new Pair[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            int tmp = Integer.parseInt(st.nextToken());
            a[tmp - 1] = ez;
        }
        for (int ez = 0; ez < n; ez++)
            pair[ez] = new Pair(a[ez], 0);
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            int tmp = Integer.parseInt(st.nextToken());
            a[tmp - 1] = ez;
        }
        for (int ez = 0; ez < n; ez++)
            pair[ez].second = a[ez];
        // 按第一组排序后对第二组求LIS
        Arrays.sort(pair, (x, y) -> x.first - y.first);
        for (int ez = 0; ez < n; ez++)
            a[ez] = pair[n - 1 - ez].second;
        pw.println(LIS());
        pw.close();
    }

    private static int LIS() {
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = a[0];
        int len = 1;
        for (int ez = 1; ez < n; ez++) {
            if (a[ez] > dp[len - 1])
                dp[len++] = a[ez];
            else {
                int pos = Arrays.binarySearch(dp, 0, len, a[ez]);
                if (pos < 0)
                    pos = -(pos + 1);
                dp[pos] = a[ez];
            }
        }
        return len;
    }

}
