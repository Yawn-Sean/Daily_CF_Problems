import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] time = new int[k];
        for (int i = 0; i < k; i++)
            time[i] = Integer.parseInt(st.nextToken());
        int allT = 0;
        for (int tt : time)
            allT += tt;
        Arrays.sort(time);
        int res = 0;
        for (int ez = 0; ez <= n; ez++) {
            if (allT * ez > m)
                break;
            int ans = ez * (k + 1);
            int tmp = m - allT * ez;
            int maxCan = n - ez;
            for (int now : time) {
                int minX = Math.min(maxCan, tmp / now);
                ans += minX;
                tmp -= minX * now;
            }
            res = Math.max(res, ans);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
