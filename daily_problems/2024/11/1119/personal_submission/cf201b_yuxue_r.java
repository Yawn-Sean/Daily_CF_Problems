import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long a = 0, b1 = 0, b2 = 0, c = 0;
        for (int i = 2; i < 4 * n; i += 4) {
            for (int j = 2; j < 4 * m; j += 4) {
                int x = scanner.nextInt();
                a += x;
                b1 += 2 * x * i;
                b2 += 2 * x * j;
                c += 1L * x * (i * i + j * j);
            }
        }

        int x = search(a, b1) * 4;
        int y = search(a, b2) * 4;
        System.out.println(a * (x * x + y * y) - b1 * x - b2 * y + c);
        System.out.println(x / 4 + " " + y / 4);

        scanner.close();
    }
    private static int search(long a, long b) {
        if (a == 0) return 0;
        int x = (int) (b / a / 8);
        return Math.abs(8 * a * x - b) <= Math.abs(8 * a * (x + 1) - b) ? x : x + 1;
    }
}
