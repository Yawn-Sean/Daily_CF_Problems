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
        int[] a = new int[n + 2];
        int[] d = new int[n + 2];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++) {
            a[ez] = Integer.parseInt(st.nextToken());
            d[ez] = a[ez] - a[ez - 1];
        }
        d[n + 1] = -a[n];
        long res = 0;
        for (int ez = 1; ez <= n; ez++) {
            if (d[ez] > 0)
                res += d[ez];
        }
        pw.println(res);
        n++;
        for (int right = 1, left = 1; right <= n; right++) {
            while (d[right] < 0) {
                while (d[left] <= 0)
                    left++;
                d[right]++;
                d[left]--;
                pw.println(left + " " + (right - 1));
            }
        }
        pw.close();
        f.close();
    }

}
