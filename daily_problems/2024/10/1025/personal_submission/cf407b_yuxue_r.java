import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, mod = 1_000_000_007;
        n = scanner.nextInt();

        int[] toPos = new int[n];
        for (int i = 0; i < n; i++) {
            toPos[i] = scanner.nextInt() - 1;
        }

        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);
        
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + dp[i];
            if (dp[i + 1] >= mod) dp[i + 1] -= mod;

            dp[i + 1] -= dp[toPos[i]];
            if (dp[i + 1] < 0) dp[i + 1] += mod;

            dp[i + 1] += 2;
            if (dp[i + 1] >= mod) dp[i + 1] -= mod;
        }
        
        System.out.println(dp[n]);
    }
}
