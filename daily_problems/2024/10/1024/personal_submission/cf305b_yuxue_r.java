import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long p = scanner.nextLong();
        long q = scanner.nextLong();

        ArrayList<Long> list = new ArrayList<>();

        while (q != 0) {
            list.add(p / q);
            p %= q;
            long temp = p;
            p = q;
            q = temp;
        }

        int n = scanner.nextInt();

        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextLong();
        }

        if (n > 1 && nums[n - 1] == 1) {
            nums = removeLastElement(nums);
            n--;
            nums[n - 1]++;
        }

        if (list.size() == n) {
            boolean match = true;
            for (int i = 0; i < n; i++) {
                if (nums[i] != list.get(i)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }

    private static long[] removeLastElement(long[] array) {
        long[] result = new long[array.length - 1];
        System.arraycopy(array, 0, result, 0, result.length);
        return result;
    }
}
