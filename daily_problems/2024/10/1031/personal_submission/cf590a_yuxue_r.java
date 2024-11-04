import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        AtomicInteger ans = new AtomicInteger();

        java.util.function.BiConsumer<Integer, Integer> op = (l, r) -> {
            ans.set(Math.max(ans.get(), (r - l - 1) / 2));
            for (int i = l; i < (l + r) / 2; i++) {
                nums[i] = nums[l];
            }
            for (int i = (l + r) / 2; i < r; i++) {
                nums[i] = nums[r - 1];
            }
        };

        int l = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                op.accept(l, i);
                l = i;
            }
        }

        op.accept(l, n);

        System.out.println(ans.get());
        for (int x : nums) {
            System.out.print(x + " ");
        }
    }
}
