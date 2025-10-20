import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    private static final int[] PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    private static final int COUNT = PRIMES.length;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] a = new int[n];
            st = new StringTokenizer(br.readLine());
            boolean hasOne = false;
            Set<Integer> numSet = new HashSet<>();
            for (int ez = 0; ez < n; ez++) {
                a[ez] = Integer.parseInt(st.nextToken());
                if (a[ez] == 1)
                    hasOne = true;
                numSet.add(a[ez]);
            }
            if (hasOne) {
                pw.println(-1);
                continue;
            }
            long minM = Long.MAX_VALUE;
            for (int mask = 1; mask < (1 << COUNT); mask++) {
                long m = 1;
                for (int ez = 0; ez < COUNT; ez++) {
                    if ((mask & (1 << ez)) != 0) {
                        m *= PRIMES[ez];
                        if (m >= minM)
                            break;
                    }
                }
                if (m >= minM)
                    continue;
                boolean valid = true;
                for (int num : numSet) {
                    if (gcd(num, m) < 2) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    minM = m;
            }
            pw.println(minM);
        }
        pw.close();
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

}
