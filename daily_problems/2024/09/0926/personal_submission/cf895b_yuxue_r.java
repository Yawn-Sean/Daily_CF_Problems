import java.util.*;

public class cf895b_yuxue_r {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int k = scanner.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        Arrays.sort(nums);

        long ans = 0;
        for (int v : nums) {
            int l = (v - 1) / x + k;
            int lowerBound1 = lowerBound(nums, Math.max(v, (long) l * x));
            int lowerBound2 = lowerBound(nums, (long) (l + 1) * x);
            ans += lowerBound2 - lowerBound1;
        }

        System.out.println(ans);

        scanner.close();
    }

    private static int lowerBound(int[] arr, long target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
