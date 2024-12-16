import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long l = Long.valueOf(st.nextToken());
        long r = Long.valueOf(st.nextToken());
        long res = Math.max(getMax(l), getMax(r));
        // 具体为啥有时候是5最大而不是4我也没搞懂
        long t = 5;
        for (int ez = 0; ez <= 9; ez++) {
            if (l <= t && t <= r)
                res = Math.max(res, getMax(t));
            t *= 10;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long getMax(long x) {
        long t = 1;
        while (t <= x)
            t *= 10;
        return x * (t - x - 1);
    }

}
