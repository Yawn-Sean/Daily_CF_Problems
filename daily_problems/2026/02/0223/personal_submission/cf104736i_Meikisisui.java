import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        st = new StringTokenizer(br.readLine());
        Long n = Long.parseLong(st.nextToken());
        char[] ch = s.toCharArray();
        int[] cnt = new int[26];
        int m = s.length();
        long res = 0;
        for (int ez = 0; ez < m; ez++) {
            int now = ch[ez] - 'a';
            for (int vn = now + 1; vn < 26; vn++) {
                res += cnt[vn];
                res %= MOD;
            }
            cnt[now]++;
        }
        res *= (n % MOD);
        res %= MOD;
        for (int ez = 0; ez < 26; ez++) {
            for (int vn = ez + 1; vn < 26; vn++) {
                long pairs = n % MOD;
                pairs = pairs * ((n - 1) % MOD) % MOD;
                pairs = pairs * 500000004 % MOD;
                long tmp = (long) cnt[ez] * cnt[vn] % MOD;
                tmp = tmp * pairs % MOD;
                res = (res + tmp) % MOD;
            }
        }
        pw.println(res);
        pw.close();
    }

}
