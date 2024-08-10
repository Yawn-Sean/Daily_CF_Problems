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
        long x = Integer.parseInt(st.nextToken());
        long[][] nums = new long[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            nums[ez][0] = Long.parseLong(st.nextToken());
            nums[ez][1] = Long.parseLong(st.nextToken());
        }
        long res = bulbo(n, x, nums);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long bulbo(int n, long x, long[][] nums) {
        long left = x, right = x;
        long res = 0;
        // 加几行注释看看是不是cf崩了
        for (int ez = 0; ez < n; ez++) {
            long begin = nums[ez][0];
            long end = nums[ez][1];
            if (begin <= left && right <= end)
                continue;
            if (left > end) {
                res += left - end;
                right = left;
                left = end;
            } else if (right < begin) {
                res += begin - right;
                left = right;
                right = begin;
            } else {
                left = Math.max(left, begin);
                right = Math.min(right, end);
            }
        }
        return res;
    }

}
