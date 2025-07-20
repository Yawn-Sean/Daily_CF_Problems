import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int[] b = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < m; ez++)
            b[ez] = Integer.parseInt(st.nextToken());
        Arrays.sort(a);
        Arrays.sort(b);
        int vn = m - 1;
        int pointA = n, pointB = m;
        int cntA = 0, cntB = 0;
        for (int ez = n - 1; ez >= 0; ez--) {
            while (vn >= 0 && a[ez] <= b[vn]) {
                vn--;
                cntB++;
            }
            cntA++;
            if (cntA - cntB >= pointA - pointB) {
                pointA = cntA;
                pointB = cntB;
            }
        }
        if (pointA < pointB) {
            pointA = 0;
            pointB = 0;
        }
        pw.println((n * 2 + pointA) + ":" + (m * 2 + pointB));
        pw.close();
        br.close();
    }

}
