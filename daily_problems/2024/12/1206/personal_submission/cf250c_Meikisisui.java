import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] a = new int[n + 2];
        int[] cnt = new int[k + 1];
        a[0] = 0;
        int len = 1;
        for (int ez = 1; ez <= n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            if (now != a[len - 1])
                a[len++] = now;
        }
        a[0] = a[len] = 0;
        for (int ez = 1; ez < len; ez++) {
            if (a[ez - 1] == a[ez + 1])
                cnt[a[ez]] += 2;
            else
                cnt[a[ez]] += 1;
        }
        int res = 1;
        for (int ez = 2; ez <= k; ez++) {
            if (cnt[ez] > cnt[res])
                res = ez;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
