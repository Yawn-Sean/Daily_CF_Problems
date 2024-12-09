import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] nums1 = new long[n];
        long[] nums2 = new long[n];
        for (int i = 0; i < n; i++) {
            nums1[i] = scanner.nextLong();
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = scanner.nextLong();
        }
        long[] acc1 = new long[n + 1];
        long[] acc2 = new long[n + 1];
        for (int i = 0; i < n; i++) {
            acc1[i + 1] = acc1[i] + nums1[i];
            acc2[i + 1] = acc2[i] + nums2[i];
        }
        long[] dp1 = new long[n + 1];
        long[] dp2 = new long[n + 1];
        Arrays.fill(dp1, 0);
        Arrays.fill(dp2, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp1[i] = dp1[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2L * i * nums1[i] + (2L * n - 1) * nums2[i];
            dp2[i] = dp2[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2L * i * nums2[i] + (2L * n - 1) * nums1[i];
        }

        long ans = dp1[0];
        long cur = 0;
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 1) {
                cur += 2L * i * nums2[i] + (2L * i + 1) * nums1[i];
                ans = Math.max(ans, cur + dp1[i + 1]);
            } else {
                cur += 2L * i * nums1[i] + (2L * i + 1) * nums2[i];
                ans = Math.max(ans, cur + dp2[i + 1]);
            }
        }
        System.out.println(ans);
    }
}
