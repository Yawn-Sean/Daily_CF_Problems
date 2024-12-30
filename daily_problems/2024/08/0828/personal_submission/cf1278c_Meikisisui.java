import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int n;
    private static int[] nums;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(f.readLine());
            n = Integer.parseInt(st.nextToken());
            nums = new int[2 * n];
            st = new StringTokenizer(f.readLine());
            for (int ez = 0; ez < 2 * n; ez++) {
                int now = Integer.parseInt(st.nextToken());
                nums[ez] = now == 1 ? now : -1;
            }
            int res = berryJam(n, nums);
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static int berryJam(int n, int[] nums) {
        Map<Integer, Integer> preMap = new HashMap<>();
        preMap.put(0, -1);
        int sum = 0;
        // 前缀大值，后缀小值
        for (int ez = 0; ez < n; ez++) {
            sum += nums[ez];
            preMap.put(sum, ez);
        }
        sum = 0;
        int res = 2 * n;
        if (preMap.containsKey(0))
            res = Math.min(res, 2 * n - preMap.get(0) - 1);
        for (int ez = 2 * n - 1; ez >= n; ez--) {
            sum += nums[ez];
            int temp = -sum;
            if (preMap.containsKey(temp))
                res = Math.min(res, ez - preMap.get(temp) - 1);
        }
        return res;
    }

}
