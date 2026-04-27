import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long ou = n / 2, ji = n - ou;
            long cnt1 = (ji * ou * (ji - 1) / 2) % MOD;
            long cnt2 = (ou * (ou - 1) * (ou - 2) / 6) % MOD;
            long res = (cnt1 + cnt2) % MOD;
            pw.println(res);
        }
        pw.close();
    }
}
