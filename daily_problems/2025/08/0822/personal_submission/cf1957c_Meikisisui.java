import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        long[] f = new long[300001];
        f[0] = 1;
        f[1] = 1;
        f[2] = 3;
        for (int ez = 3; ez < 300001; ez++)
            f[ez] = (f[ez - 1] + (f[ez - 2] * 2 * (ez - 1)) % MOD) % MOD;
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int cnt = 0;
            for (int ez = 0; ez < k; ez++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if (a == b)
                    cnt++;
                else
                    cnt += 2;
            }
            pw.println(f[n - cnt]);
        }
        pw.close();
    }

}
