import javafx.util.Pair;

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
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Integer>[] nums = new List[m + 1];
        Arrays.setAll(nums, k -> new ArrayList<Integer>());
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            int s = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            nums[s].add(r);
        }
        for (List<Integer> num : nums) num.sort(Collections.reverseOrder());
        int[] ans = new int[n + 1];
        for (int ez = 1; ez < nums.length; ez++) {
            int sum = 0;
            for (int vn = 0; vn < nums[ez].size(); vn++) {
                sum += nums[ez].get(vn);
                if (sum < 0)
                    break;
                ans[vn + 1] += sum;
            }
        }
        int res = 0;
        for (int ez = 0; ez <= n; ez++)
            res = Math.max(res, ans[ez]);
        pw.println(res);
        pw.close();
        f.close();
    }

}
