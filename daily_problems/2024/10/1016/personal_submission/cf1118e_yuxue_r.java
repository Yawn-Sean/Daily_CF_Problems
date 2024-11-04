import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();

        if (k <= 1000 && n > k * (k - 1)) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (int i = 1; i <= k; i++) {
                for (int j = 1; j < i && n > 0; j++) {
                    System.out.println(j + " " + i);
                    n--;
                    if (n > 0) {
                        System.out.println(i + " " + j);
                        n--;
                    }
                }
            }
        }

        scanner.close();
    }
}
