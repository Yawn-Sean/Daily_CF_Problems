import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int l1 = Integer.parseInt(st.nextToken());
        int r1 = Integer.parseInt(st.nextToken());
        int t1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int l2 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int t2 = Integer.parseInt(st.nextToken());
        int step = gcd(t1, t2);
        int dis = ((l2 - l1) % step + step) % step;
        int res = 0;
        res = Math.max(res, Math.min(l2 - dis + r1 - l1 - l2 + 1, r2 - l2 + 1));
        dis -= step;
        res = Math.max(res, Math.min(r2 - (l2 - dis) + 1, r1 - l1 + 1));
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

}
