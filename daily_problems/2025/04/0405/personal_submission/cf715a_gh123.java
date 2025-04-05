//https://codeforces.com/problemset/submission/715/314001402
import java.util.Scanner;

public class A715 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println(2);
        for (long i = 2; i <= n; i++) {
            System.out.println(i * i * i + 2 * i * i + 1);
        }
        sc.close();
    }
}
