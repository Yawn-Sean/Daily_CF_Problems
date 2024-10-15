import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] nums = new int[n];
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        double res = protest(n, nums);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static double protest(int n, int[] nums) {
        double res = 0;
        Arrays.sort(nums);
        int mx = nums[n - 1], cnt = 0;
        long[] p1 = new long[10001], p2 = new long[10001];
        for (int ez = 0; ez < n - 1; ez++) {
            for (int vn = ez + 1; vn < n; vn++) {
                p1[nums[vn] - nums[ez]]++;
                cnt++;
            }
        }
        for (int ez = 0; ez < mx; ez++) {
            for (int vn = 0; vn < mx; vn++)
                p2[ez + vn] += p1[ez] * p1[vn];
        }
        for (int ez = 0; ez < mx; ez++) {
            for (int vn = 0; vn < ez; vn++)
                res += (double) (p1[ez] * p2[vn]) / cnt / cnt / cnt;
        }
        return res;
    }

}
