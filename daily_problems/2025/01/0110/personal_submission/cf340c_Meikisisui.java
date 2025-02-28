import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] a = new long[n + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        Arrays.sort(a, 1, n + 1);
        long ans = 0;
        for (int ez = 1; ez <= n; ez++)
            ans += (4L * ez - 2L * n - 1) * a[ez];
        long g = gcd(ans, n);
        pw.println((ans / g) + " " + (n / g));
        pw.close();
        f.close();
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

}
