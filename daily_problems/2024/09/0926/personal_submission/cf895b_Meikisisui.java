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
        long x = Integer.parseInt(st.nextToken());
        long k = Integer.parseInt(st.nextToken());
        long[] a = new long[n + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        Arrays.sort(a, 1, n + 1);
        long res = 0;
        for (int ez = 1; ez <= n; ez++) {
            long left = 0, right = 0;
            // k为0特判
            if (k == 0) {
                if (a[ez] % x == 0)
                    continue;
                left = a[ez];
                right = (a[ez] + x - 1) / x * x - 1;
            } else {
                left = (a[ez] + x - 1) / x * x + (k - 1) * x;
                right = left + x - 1;
            }
            res += upperBound(a, 1, n + 1, right) - lowerBound(a, 1, n + 1, left);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int lowerBound(long[] a, int left, int right, long target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    // 没想到合成一个方法的办法懒得想了
    private static int upperBound(long[] a, int left, int right, long target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

}
