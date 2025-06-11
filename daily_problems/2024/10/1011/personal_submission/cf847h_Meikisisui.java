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
        int[] nums = new int[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        long[] left = new long[n];
        long[] sumLeft = new long[n];
        left[0] = nums[0];
        for (int ez = 1; ez < n; ez++) {
            left[ez] = Math.max(nums[ez], left[ez - 1] + 1);
            sumLeft[ez] = sumLeft[ez - 1] + left[ez] - nums[ez];
        }
        long[] right = new long[n];
        long[] sumRight = new long[n];
        right[n - 1] = nums[n - 1];
        for (int ez = n - 2; ez >= 0; ez--) {
            right[ez] = Math.max(nums[ez], right[ez + 1] + 1);
            sumRight[ez] = sumRight[ez + 1] + right[ez] - nums[ez];
        }
        long res = Math.min(sumRight[0], sumLeft[n - 1]);
        for (int ez = 0; ez < n - 1; ez++) {
            long tmp = sumLeft[ez] + sumRight[ez + 1] + (left[ez] > right[ez + 1] ? 0 : right[ez + 1] + 1 - left[ez]);
            res = Math.min(res, tmp);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
