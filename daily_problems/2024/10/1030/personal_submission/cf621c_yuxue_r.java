import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();

        ArrayList<Double> probs = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            double prob = 1.0 * (r / p - (l - 1) / p) / (r - l + 1);
            probs.add(prob);
        }
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += probs.get(i);
            ans += probs.get((i + 1) % n);
            ans -= probs.get(i) * probs.get((i + 1) % n);
        }

        System.out.println(ans * 2000);
    }
}
