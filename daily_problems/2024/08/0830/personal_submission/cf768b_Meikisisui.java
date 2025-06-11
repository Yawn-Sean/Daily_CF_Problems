import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static long n;
    private static long left, right;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Long.parseLong(st.nextToken());
        left = Long.parseLong(st.nextToken());
        right = Long.parseLong(st.nextToken());
        long res = codeForOne();
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long codeForOne() {
        long res = 0;
        for (long ez = left; ez <= right; ez++)
            res += dfs(n, ez);
        return res;
    }

    // 数字 x 分裂后的序列的第 ez 项的值
    private static long dfs(long x, long ez) {
        long mid = 1;
        long t = x;
        while (t >> 1 > 0) {
            t >>= 1;
            mid <<= 1;
        }
        if (ez < mid)
            return dfs(x >> 1, ez);
        else if (ez == mid)
            return x % 2;
        else
            return dfs(x >> 1, ez - mid);
    }

}
