import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    private static List<Integer> res = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];
        for (int ez = 1; ez <= n; ez++)
            arr[ez] = Integer.parseInt(st.nextToken());
        if (k == 0) {
            for (int ez = 1; ez <= n; ez++)
                pw.print(arr[ez] + " ");
            pw.close();
            br.close();
            return;
        }
        int left = 1, right = 1000000001, ans = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (checkMid(mid, arr, n, k)) {
                ans = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (ans == -1) {
            pw.println("-1");
        } else {
            long sum = 0;
            int pos = -1;
            for (int ez = 1; ez <= n; ez++)
                sum += Math.min(arr[ez], ans - 1);
            for (int ez = 1; ez <= n; ez++) {
                if (arr[ez] >= ans)
                    sum++;
                if (sum == k) {
                    pos = ez;
                    break;
                }
            }
            for (int ez = pos + 1; ez <= n; ez++) {
                if (arr[ez] >= ans)
                    res.add(ez);
            }
            for (int ez = 1; ez <= pos; ez++) {
                if (arr[ez] >= ans + 1)
                    res.add(ez);
            }
            for (int ez = 0; ez < res.size(); ez++)
                pw.print(res.get(ez) + " ");
        }
        pw.close();
        br.close();
    }

    private static boolean checkMid(int mid, int[] arr, int n, long k) {
        long res = 0;
        for (int ez = 1; ez <= n; ez++)
            res += Math.min(mid, arr[ez]);
        return res >= k;
    }

}
