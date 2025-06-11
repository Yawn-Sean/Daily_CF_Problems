import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long c = Long.parseLong(st.nextToken());
        long res = Long.MAX_VALUE;
        if (a % 2 == b % 2)
            res = Math.min(res, getCnt(a, b) * 2 + Math.min(a, b));
        if (b % 2 == c % 2)
            res = Math.min(res, getCnt(b, c) * 2 + Math.min(b, c));
        if (c % 2 == a % 2)
            res = Math.min(res, getCnt(c, a) * 2 + Math.min(c, a));
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long getCnt(long a, long b) {
        return (Math.max(a, b) - Math.min(a, b)) / 2;
    }

}
