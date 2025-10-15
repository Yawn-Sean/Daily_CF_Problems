import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] nums = new int[n];
        long tot = 0;

        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
            tot += nums[i];
        }

        int l, r;
        int ans = 0;
        l = Integer.MAX_VALUE;
        r = (int) (tot / n);

        for (int num : nums) {
            if (num < l) l = num;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            int cur = 0;
            for (int v : nums) {
                cur += Math.max(m - v, 0);
                if (cur > k) break;
            }
            if (cur > k) r = m - 1;
            else l = m + 1;
        }

        ans -= r;
        l = (int) ((tot + n - 1) / n);
        r = Integer.MIN_VALUE;

        for (int num : nums) {
            if (num > r) r = num;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            int cur = 0;
            for (int v : nums) {
                cur += Math.max(v - m, 0);
                if (cur > k) break;
            }
            if (cur > k) l = m + 1;
            else r = m - 1;
        }
        ans += l;
        System.out.println(ans);
        scanner.close();
    }
}
