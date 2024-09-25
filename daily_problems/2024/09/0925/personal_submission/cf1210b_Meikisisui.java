import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] a = new long[n];
        long[] b = new long[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            b[ez] = Long.parseLong(st.nextToken());

        Map<Long, Integer> cntMap = new HashMap<>();
        Map<Long, Long> bMap = new HashMap<>();
        long[] arr = new long[n + 1];
        for (int ez = 0; ez < n; ez++) {
            long key = a[ez];
            cntMap.put(key, cntMap.getOrDefault(key, 0) + 1);
            bMap.put(key, bMap.getOrDefault(key, 0L) + b[ez]);
        }
        long res = 0;
        int m = 0;
        for (int ez = 0; ez < n; ez++) {
            if (cntMap.get(a[ez]) >= 2) {
                res += bMap.get(a[ez]);
                cntMap.put(a[ez], 0);
                arr[m++] = a[ez];
            }
        }
        for (int ez = 0; ez < n; ez++) {
            if (cntMap.get(a[ez]) != 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    long t1 = a[ez] ^ arr[j];
                    long t2 = a[ez] | arr[j];
                    if (t1 != 0 && t2 != arr[j])
                        continue;
                    flag = 1;
                    break;
                }
                if (flag == 1) {
                    res += b[ez];
                    m++;
                    arr[m] = a[ez];
                }
            }
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
