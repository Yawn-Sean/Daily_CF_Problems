import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        nextVisit = new int[n + 1];
        for (int ez = 1; ez <= n; ez++)
            nextVisit[ez] = Integer.parseInt(st.nextToken());
        pw.println(firstDayBeenInAllRooms(nextVisit));
        pw.close();
        f.close();
    }

    private static int n;
    private static int[] nextVisit;
    private static int[] memo;
    private static int MOD = 1_000_000_007;

    public static int firstDayBeenInAllRooms(int[] nextVisit) {
        memo = new int[n + 2];
        Arrays.fill(memo, -1);
        int res = dfs(n + 1);
        return res;
    }

    private static int dfs(int i) {
        if (i <= 1)
            return 0;
        if (i == 2)
            return memo[2] = 2;
        if (-1 != memo[i])
            return memo[i];
        int res = ((dfs(i - 1) * 2) % MOD - dfs(nextVisit[i - 1]) + 2 + MOD) % MOD;
        return memo[i] = res;
    }

}
