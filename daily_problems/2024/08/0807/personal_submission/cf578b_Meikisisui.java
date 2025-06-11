import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] nums = new int[n];
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        long res = orGame(n, k, x, nums);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static long orGame(int n, int k, int x, int[] nums) {
        long beishu = 1;
        for (int ez = 0; ez < k; ez++)
            beishu *= x;
        int[] pre = new int[n];
        int[] suf = new int[n];
        for (int ez = 0; ez < n - 1; ez++)
            pre[ez + 1] = pre[ez] | nums[ez];
        for (int ez = n - 1; ez > 0; ez--)
            suf[ez - 1] = suf[ez] | nums[ez];
        long res = 0;
        for (int ez = 0; ez < n; ez++)
            res = Math.max(res, pre[ez] | suf[ez] | (beishu * nums[ez]));
        return res;
    }

}
