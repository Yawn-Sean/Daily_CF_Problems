import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] cnt = new int[n + 1];

        while (m-- > 0) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            cnt[x]++;
            cnt[y]++;
        }

        long angles = 0;
        for (int i = 1; i <= n; i++) {
            angles += (long) cnt[i] * (n - 1 - cnt[i]);
        }
        long result = (long) n * (n - 1) * (n - 2) / 6 - angles / 2;

        System.out.println(result);
        scanner.close();
    }
}
