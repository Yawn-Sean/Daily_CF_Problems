import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String a = st.nextToken();
        st = new StringTokenizer(f.readLine());
        String b = st.nextToken();
        long lenA = a.length(), lenB = b.length();
        long gcd = gcd(lenA, lenB), lcm = lcm(lenA, lenB), res = 0;
        long ans = 0;
        int[][] arr = new int[(int) Math.max(lenA, lenB)][26];
        for (int ez = 0; ez < lenA; ez++)
            arr[(int) (ez % gcd)][a.charAt(ez) - 'a']++;
        for (int ez = 0; ez < lenB; ez++)
            ans += arr[(int) (ez % gcd)][b.charAt(ez) - 'a'];
        long cnt = lcm - ans;
        pw.println(n * lenA / lcm * cnt);
        pw.close();
        f.close();
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

}
