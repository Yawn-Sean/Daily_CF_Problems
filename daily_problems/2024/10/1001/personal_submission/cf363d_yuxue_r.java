import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int a = scanner.nextInt();

        int[] nums1 = new int[n];
        int[] nums2 = new int[m];

        for (int i = 0; i < n; i++) {
            nums1[i] = scanner.nextInt();
        }
        for (int i = 0; i < m; i++) {
            nums2[i] = scanner.nextInt();
        }

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int l = 0, r = Math.min(n, m);

        while (l <= r) {
            int mid = (l + r) / 2;
            int cur = 0;
            boolean flg = true;
            for (int i = 0; i < mid; i++) {
                cur += Math.max(nums2[i] - nums1[n - mid + i], 0);
                if (cur > a) {
                    flg = false;
                    break;
                }
            }
            if (flg) l = mid + 1;
            else r = mid - 1;
        }

        int ans = -a;
        for (int i = 0; i < r; i++) {
            ans += nums2[i];
        }

        System.out.println(r + " " + Math.max(0, ans));

        scanner.close();
    }
}
