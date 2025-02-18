import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int limit = 1 << n;

        for (int i = 0; i < limit; i++) {
            for (int j = 0; j < limit; j++) {
                int popcount = Integer.bitCount(i | j);
                System.out.print((popcount % 2 == 1) ? '+' : '*');
            }
            System.out.println();
        }

        scanner.close();
    }
}
