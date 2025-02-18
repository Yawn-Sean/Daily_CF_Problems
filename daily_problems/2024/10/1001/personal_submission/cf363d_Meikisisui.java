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
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] a = new int[n + 1];
        int[] b = new int[m + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= m; ez++)
            b[ez] = Integer.parseInt(st.nextToken());

        Arrays.sort(a, 1, n + 1);
        Arrays.sort(b, 1, m + 1);
        int left = 1, right = Math.min(n, m), ans = 0;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (check(mid, a, b, k)) {
                left = mid + 1;
                ans = mid;
            } else
                right = mid - 1;
        }
        long cnt = 0;
        for (int ez = 1; ez <= ans; ez++)
            cnt += b[ez];
        int temp = ans;
        long res = 0;
        if (cnt <= k)
            res = 0;
        else
            res = cnt - k;
        pw.println(temp + " " + res);
        pw.close();
        f.close();
    }

    public static boolean check(int x, int[] a, int[] b, int k) {
        int n = a.length - 1;
        long cnt = 0;
        for (int ez = x; ez >= 1; ez--) {
            if (a[n + ez - x] < b[ez])
                cnt += (b[ez] - a[n + ez - x]);
        }
        if (cnt <= k)
            return true;
        else
            return false;
    }

}
