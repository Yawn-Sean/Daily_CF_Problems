import java.util.Scanner;
// yuxue_r's submission for cf731f
public class cf731f_yuxue_r {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int M = (int) (2e5);


        int n = scanner.nextInt();
        int[] nums = new int[n];
        int[] acc = new int[M + 2];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
            acc[nums[i] + 1]++;
        }


        for (int i = 0; i <= M; i++) {
            acc[i + 1] += acc[i];
        }

        long[] ans = new long[M + 1];

        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= M; j += i) {
                ans[i] += (long)j * (acc[Math.min(M + 1, j + i)] - acc[j]);
            }
        }

        long maxAns = 0;
        for (int x : nums) {
            maxAns = Math.max(maxAns, ans[x]);
        }

        System.out.println(maxAns);
    }
}
