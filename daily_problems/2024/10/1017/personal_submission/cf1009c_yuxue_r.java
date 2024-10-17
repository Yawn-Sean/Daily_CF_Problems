import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, q;
        n = scanner.nextInt();
        q = scanner.nextInt();

        long v1 = 1L * n * (n - 1) / 2;
        long v2 = 0;
        for (int i = 0; i < n; i++) {
            v2 += Math.abs(i - n / 2);
        }

        int ans = 0;
        long tot = 0;
        while (q > 0) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            ans += x;
            tot += (y >= 0 ? v1 : v2) * y;
            q--;
        }

        System.out.printf("%.20f", (double) tot / n + ans);

        scanner.close();
    }
}
