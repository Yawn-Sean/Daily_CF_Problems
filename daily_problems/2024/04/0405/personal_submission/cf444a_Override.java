import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        double[] val = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            val[i] = scanner.nextDouble();
        }
        double ans = 0;
        for (int i = 1; i <= m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            double c = scanner.nextDouble();
            ans = Math.max(ans, (val[a] + val[b]) / c);
        }
        System.out.printf("%.12f\n", ans);
    }
}
