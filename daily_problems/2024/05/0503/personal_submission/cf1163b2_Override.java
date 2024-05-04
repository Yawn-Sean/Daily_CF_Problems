import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[100005];
        int[] b = new int[100005];
        int ans = 1;

        for (int i = 1; i <= n; i++) {
            int t = scanner.nextInt();
            a[t]++;
            b[a[t]]++;

            if (a[t] * b[a[t]] == i && i != n) {
                ans = i + 1;
            }
            if (a[t] * b[a[t]] == i - 1) {
                ans = i;
            }
        }

        System.out.println(ans);
    }
}
