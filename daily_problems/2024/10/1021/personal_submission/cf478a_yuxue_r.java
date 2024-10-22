import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int hp1 = scanner.nextInt();
        int atk1 = scanner.nextInt();
        int def1 = scanner.nextInt();
        int hp2 = scanner.nextInt();
        int atk2 = scanner.nextInt();
        int def2 = scanner.nextInt();
        int h = scanner.nextInt();
        int a = scanner.nextInt();
        int d = scanner.nextInt();

        int ans = 0;
        int v = Math.max(0, def2 + 1 - atk1);
        atk1 += v;
        ans += v * a;

        int cur_h1 = Math.max(0, atk2 - def1);
        int cur_h2 = atk1 - def2;
        int new_ans = cur_h1 * d;
        for (int delta_h1 = 0; delta_h1 < cur_h1; delta_h1++) {
            for (int delta_h2 = 0; delta_h2 <= 100; delta_h2++) {
                int h1 = cur_h1 - delta_h1;
                int h2 = cur_h2 + delta_h2;
                int time = (hp2 + h2 - 1) / h2;
                int delta_hp1 = Math.max(time * h1 + 1 - hp1, 0);
                new_ans = Math.min(new_ans, delta_h1 * d + delta_h2 * a + delta_hp1 * h);
            }
        }

        System.out.println(ans + new_ans);
        scanner.close();
    }
}
