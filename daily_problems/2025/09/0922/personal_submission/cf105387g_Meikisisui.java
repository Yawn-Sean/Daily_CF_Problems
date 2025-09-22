import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int kr = Integer.parseInt(st.nextToken());
        int kg = Integer.parseInt(st.nextToken());
        int kb = Integer.parseInt(st.nextToken());
        long[] fr = new long[n + 1];
        long[] fg = new long[n + 1];
        long[] fb = new long[n + 1];
        long[] tot = new long[n + 1];
        tot[0] = 1;
        for (int ez = 1; ez <= n; ez++) {
            long subR = (ez > kr) ? (tot[ez - kr - 1] - fr[ez - kr - 1]) % MOD : 0;
            fr[ez] = (tot[ez - 1] - subR) % MOD;
            long subG = (ez > kg) ? (tot[ez - kg - 1] - fg[ez - kg - 1]) % MOD : 0;
            fg[ez] = (tot[ez - 1] - subG) % MOD;
            long subB = (ez > kb) ? (tot[ez - kb - 1] - fb[ez - kb - 1]) % MOD : 0;
            fb[ez] = (tot[ez - 1] - subB) % MOD;
            tot[ez] = (fr[ez] + fg[ez] + fb[ez]) % MOD;
            if (tot[ez] < 0)
                tot[ez] += MOD;
        }
        pw.println(tot[n]);
        pw.close();
    }


}
