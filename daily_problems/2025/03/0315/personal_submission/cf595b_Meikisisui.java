import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] a = new int[n / k];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n / k; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long res = 1;
        long powK = (long) Math.pow(10, k);
        for (int ez = 0; ez < n / k; ez++) {
            int b = Integer.parseInt(st.nextToken());
            long cnt = (powK - 1) / a[ez];
            // 容斥
            // 不考虑b有 (powK-1)/a[ez]种
            // 再减去开头是b
            if (b != 0) {
                cnt++;
                cnt -= ((b + 1) * (powK / 10) - 1) / a[ez] - (b * (powK / 10) - 1) / a[ez];
            } else
                cnt -= (powK / 10 - 1) / a[ez];
            res = (res * cnt) % MOD;
        }
        pw.println(res);
        pw.close();
        br.close();
    }

}
