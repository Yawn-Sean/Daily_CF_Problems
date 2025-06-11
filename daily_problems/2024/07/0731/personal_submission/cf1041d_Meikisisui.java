import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[] start = new int[n];
        int[] end = new int[n];
        long[] sum = new long[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            start[ez] = Integer.parseInt(st.nextToken());
            end[ez] = Integer.parseInt(st.nextToken());
            if (ez > 0)
                sum[ez] = sum[ez - 1] + start[ez] - end[ez - 1];
        }
        long res = 0;
        for (int ez = 0; ez < n; ez++) {
            long dis = h + sum[ez];
            long stop = 0;
            int vn = lowerBound(sum, dis);
            if (vn < 0) {
                vn = -vn - 2;
                stop = end[vn] + h - (sum[vn] - sum[ez]);
            } else
                stop = start[vn];
            res = Math.max(res, stop - start[ez]);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int lowerBound(long[] nums, long target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1 - left;
    }

}
