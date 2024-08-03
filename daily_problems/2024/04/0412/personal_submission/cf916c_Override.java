import java.util.Scanner;

public class Main {
    private static final int MAXX = 100003;
    private static final int INF = 0x3f3f3f3f;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int prime = MAXX;
        System.out.println(prime + " " + prime);
        System.out.println("1 2 " + (prime - n + 2));

        for (int i = 2; i < n; i++) {
            System.out.println(i + " " + (i + 1) + " 1");
        }

        int ans = m - (n - 1);
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 2; j <= n; j++) {
                if (ans == 0) {
                    return;
                }
                System.out.println(i + " " + j + " " + 1000000);
                ans--;
            }
        }
    }
}
