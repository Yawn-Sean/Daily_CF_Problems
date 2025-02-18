import java.util.Scanner;

public class cf404c {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, ans = 0;
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = scanner.nextInt();
                if (i == j) ans ^= x;
            }
        }

        int q = scanner.nextInt();

        while (q-- > 0) {
            int t = scanner.nextInt();
            if (t == 3) {
                System.out.println(ans);
            } else {
                int x = scanner.nextInt();
                ans ^= 1;
            }
        }

        scanner.close();
    }
}
