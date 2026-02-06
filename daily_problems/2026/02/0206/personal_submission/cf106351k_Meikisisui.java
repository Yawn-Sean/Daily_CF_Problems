import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    private static int MAX = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] cnt = new int[MAX + 1];
        for (int ez = 0; ez < n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            cnt[now]++;
        }
        List<Integer>[] fac = new ArrayList[MAX + 1];
        for (int ez = 1; ez <= MAX; ez++)
            fac[ez] = new ArrayList<>();
        for (int ez = 1; ez <= MAX; ez++)
            for (int vn = ez; vn <= MAX; vn += ez)
                fac[vn].add(ez);
        long res = 0;
        for (int ez = x; ez <= y; ez++) {
            int ci = cnt[ez];
            if (ci > 1)
                res += (long) ci * (ci - 1) / 2;
            List<Integer> f = fac[ez];
            int sz = f.size();
            for (int a = 0; a < sz; a++) {
                int d1 = f.get(a);
                if (d1 < x)
                    continue;
                int c1 = cnt[d1];
                if (c1 == 0)
                    continue;
                for (int b = 0; b < a; b++) {
                    int d2 = f.get(b);
                    if (d2 < x)
                        continue;
                    int c2 = cnt[d2];
                    if (c2 == 0)
                        continue;
                    int gcd = gcd(d1, d2);
                    if (gcd < x)
                        continue;
                    if ((long) d1 / gcd * d2 == ez)
                        res += (long) c1 * c2;
                }
            }
        }
        pw.println(res);
        pw.close();
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

}
