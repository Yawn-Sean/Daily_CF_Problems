import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int x, y;
        x = scanner.nextInt();
        y = scanner.nextInt();
        int a = y, b = y, cnt = 0;

        while (a < x) {
            b += a - 1;
            int temp = a;
            a = b;
            b = temp;
            cnt++;
        }
        System.out.println(cnt + 2);
        scanner.close();
    }
}
