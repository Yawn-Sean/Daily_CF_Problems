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
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] arr = new int[n + 1];
            long[] sum1 = new long[n + 2];
            long[] sum2 = new long[n + 2];
            int[] res = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++) {
                res[ez] = n + 1;
                arr[ez] = Integer.parseInt(st.nextToken());
            }
            arr[0] = arr[1];
            for (int ez = 1; ez <= n; ez++) {
                sum1[ez] = sum1[ez - 1] + arr[ez];
                sum2[ez] = sum2[ez - 1] + (arr[ez] != arr[ez - 1] ? 1 : 0);
            }
            for (int ez = 1; ez <= n; ez++) {
                int ans = -1;
                int left = 1;
                int right = ez - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (sum1[ez - 1] - sum1[mid - 1] > arr[ez]
                            && ((sum2[ez - 1] - sum2[mid] >= 1 || arr[ez - 1] > arr[ez]) || ez - 1 == mid)) {
                        ans = mid;
                        left = mid + 1;
                    } else
                        right = mid - 1;
                }
                if (ans != -1)
                    res[ez] = Math.min(res[ez], ez - ans);
            }
            for (int ez = n; ez >= 1; ez--) {
                if (ez == n) {
                    sum2[ez] = 0;
                    sum1[ez] = arr[ez];
                } else {
                    sum1[ez] = sum1[ez + 1] + arr[ez];
                    sum2[ez] = sum2[ez + 1] + (arr[ez] != arr[ez + 1] ? 1 : 0);
                }
            }
            for (int ez = 1; ez <= n; ez++) {
                int ans = -1;
                int left = ez + 1;
                int right = n;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (sum1[ez + 1] - sum1[mid + 1] > arr[ez]
                            && ((sum2[ez + 1] - sum2[mid] >= 1 || arr[ez + 1] > arr[ez]) || mid - 1 == ez)) {
                        ans = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (ans != -1)
                    res[ez] = Math.min(res[ez], ans - ez);
            }
            for (int ez = 1; ez <= n; ez++) {
                if (res[ez] == n + 1)
                    pw.print(-1 + " ");
                else
                    pw.print(res[ez] + " ");
            }
            pw.println();
        }
        pw.close();
        br.close();
    }

}
