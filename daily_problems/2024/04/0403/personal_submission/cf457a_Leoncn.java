import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();
        String b = scanner.nextLine();

        int n = Math.max(a.length(), b.length());
        a = "0".repeat(n - a.length()) + a;
        b = "0".repeat(n - b.length()) + b;

        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
        	int tx = x + y;
        	int ty = x + (a.charAt(i) - '0') - (b.charAt(i) - '0');

            x = tx;
            y = ty;
            if (x > 1) {
                System.out.println(">");
                return;
            }
            if (x < -1) {
                System.out.println("<");
                return;
            }
        }

        if (x == 0 && y == 0) {
            System.out.println("=");
        } else {
            while (Math.abs(x) < 2) {
                int temp = x;
                x = x + y;
                y = temp;
            }
            System.out.println(x > 0 ? ">" : "<");
        }
    }
}