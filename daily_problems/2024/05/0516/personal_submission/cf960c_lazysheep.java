import java.util.Scanner;
import java.util.ArrayList;

public class cf960c {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        int d = scanner.nextInt();

        ArrayList<Long> ans = new ArrayList<>();
        long cur = 1;
        for (int i = 30; i > 0; i--) {
            int v = (1 << i) - 1;
            while (x >= v) {
                for (int j = 0; j < i; j++) {
                    ans.add(cur);
                }
                cur += d;
                x -= v;
            }
        }

        System.out.println(ans.size());
        for (Long num : ans) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
