import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n, q, mod = 1000000007;
        n = scanner.nextInt();
        q = scanner.nextInt();

        String s = scanner.next();

        int[] acc_1 = new int[n + 1];
        int[] pw_2 = new int[n + 1];
        pw_2[0] = 1;

        for (int i = 0; i < n; i++) {
            acc_1[i + 1] = acc_1[i] + (s.charAt(i) - '0');
            pw_2[i + 1] = (pw_2[i] * 2) % mod;
        }

        while (q-- > 0) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            l--;
            int ans = pw_2[r - l] - pw_2[r - l - (acc_1[r] - acc_1[l])];
            if (ans < 0) ans += mod;
            System.out.println(ans);
        }
        scanner.close();
    }
}
