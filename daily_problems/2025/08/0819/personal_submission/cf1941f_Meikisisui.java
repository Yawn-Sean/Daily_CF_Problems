import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            long[] a = new long[n], d = new long[m], f = new long[k];
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < n; ez++)
                a[ez] = Long.parseLong(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < m; ez++)
                d[ez] = Long.parseLong(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < k; ez++)
                f[ez] = Long.parseLong(st.nextToken());
            long max1 = 0, max2 = 0, left = 0, right = 0;
            for (int ez = 0; ez < n - 1; ez++) {
                if (a[ez + 1] - a[ez] > max1) {
                    left = a[ez];
                    right = a[ez + 1];
                    max2 = max1;
                    max1 = a[ez + 1] - a[ez];
                } else if (a[ez + 1] - a[ez] > max2)
                    max2 = a[ez + 1] - a[ez];
            }
            if (max1 == max2) {
                pw.println(max1);
            } else {
                Arrays.sort(d);
                Arrays.sort(f);
                long mid = (left + right) / 2;
                for (int ez = 0, vn = k - 1; ez < m; ez++) {
                    while (vn > 0 && d[ez] + f[vn] >= mid) {
                        long cur = d[ez] + f[vn];
                        if (left <= cur && cur <= right)
                            max1 = Math.min(max1, Math.max(cur - left, right - cur));
                        vn--;
                    }
                    long cur = d[ez] + f[vn];
                    if (left <= cur && cur <= right)
                        max1 = Math.min(max1, Math.max(cur - left, right - cur));
                }
                pw.println(Math.max(max1, max2));
            }
        }
        pw.close();
    }

}
