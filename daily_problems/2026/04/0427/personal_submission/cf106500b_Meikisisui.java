import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static long[] memo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        memo = new long[n + 1];
        Arrays.fill(memo, -1);
        int ji = (n + 1) / 2, ou = n / 2;
        long res = fa(ji) * fa(ou);
        pw.println(res);
        pw.close();
    }

    private static long fa(int x) {
        if (-1 != memo[x])
            return memo[x];
        long res = 1;
        for (int i = 2; i <= x; i++)
            res *= i;
        return memo[x] = res;
    }
}
