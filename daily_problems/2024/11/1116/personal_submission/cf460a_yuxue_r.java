import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] nums = new int[n];
        Integer[] order = new Integer[n];
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
            order[i] = i;
        }

        Arrays.sort(order, (i, j) -> Integer.compare(nums[i], nums[j]));
        for (int i = 0; i < n; i += 2) {
            ans[order[i]] = 1;
        }
        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
