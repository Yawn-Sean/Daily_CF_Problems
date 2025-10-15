import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long l = Long.parseLong(st.nextToken()), r = l;
            int[] a = new int[n + 1], p = new int[n + 2];
            int res = 0;
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++) {
                a[ez] = Integer.parseInt(st.nextToken());
                if (ez == 1)
                    p[ez] = p[0] = a[ez];
                else
                    p[ez] = p[ez - 1] ^ a[ez];
            }
            res = p[n];
            if (n % 2 == 0) {
                res ^= p[n / 2];
                p[n + 1] = res;
            }
            if (r <= n) {
                pw.println(a[(int) r]);
                continue;
            }
            if ((r & 1) == 1)
                r--;
            pw.println(getAns(r, n, res, p));
        }
        pw.close();
    }

    private static int getAns(long r, int n, int res, int[] p) {
        if (r / 2 <= n)
            return p[(int) (r / 2)];
        if (((r / 2) & 1) == 1)
            return res;
        else
            return res ^ getAns(r / 2, n, res, p);
    }

}
