import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long c = scanner.nextLong();

        long ans = 1L << 31;
        if (((a ^ b ^ 1) & 1) == 1) {
            ans = Math.min(ans, Math.max(a, b));
        }
        if (((a ^ c ^ 1) & 1) == 1) {
            ans = Math.min(ans, Math.max(a, c));
        }
        if (((b ^ c ^ 1) & 1) == 1) {
            ans = Math.min(ans, Math.max(b, c));
        }
        System.out.println(ans);

        scanner.close();
    }
}
