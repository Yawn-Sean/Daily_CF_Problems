import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int M = 500005;
        int[] dp = new int[M + 10];
        int[] dpAcc = new int[M + 10];
        for (int i = 1; i < M; i++) {
            if (dpAcc[i] - dpAcc[i / 2] != i - i / 2) {
                dp[i] = 1;
            }
            dpAcc[i + 1] = dpAcc[i] + dp[i];
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (dp[n] == 1) {
                out.println("mastermei");
            } else {
                out.println("the greatest");
            }
        }
        out.flush();
        br.close();
        out.close();
    }
}
