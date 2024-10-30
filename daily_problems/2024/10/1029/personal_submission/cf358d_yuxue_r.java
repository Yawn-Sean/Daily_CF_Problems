import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] nums0 = new int[n];
        int[] nums1 = new int[n];
        int[] nums2 = new int[n];

        for (int i = 0; i < n; i++) {
            nums0[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            nums1[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = scanner.nextInt();
        }

        int dp0 = nums0[0];
        int dp1 = nums1[0];

        for (int i = 1; i < n; i++) {
            int tmp = Math.max(dp0 + nums1[i], dp1 + nums0[i]);
            dp1 = Math.max(dp0 + nums2[i], dp1 + nums1[i]);
            dp0 = tmp;
        }

        System.out.println(dp0);

        scanner.close();
    }
}
