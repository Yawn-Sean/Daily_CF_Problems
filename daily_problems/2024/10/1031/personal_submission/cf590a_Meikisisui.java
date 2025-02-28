import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int[] a = new int[n];
        for (int ez = 0; ez < n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        int res = 0;
        int[] arrA = new int[n];
        for (int ez = 0; ez < n; ) {
            int vn = ez;
            while (vn < n - 1 && a[vn] != a[vn + 1])
                vn++;
            res = Math.max(res, (vn - ez) / 2);
            if (vn - ez < 2) {
                arrA[ez] = a[ez];
                arrA[vn] = a[vn];
            } else if ((vn - ez - 1) % 2 == 1) {
                for (int ks = ez; ks <= vn; ks++)
                    arrA[ks] = a[ez];
            } else {
                for (int ks = ez; ks <= ez + (vn - ez - 1) / 2; ks++)
                    arrA[ks] = a[ez];
                for (int ks = ez + (vn - ez - 1) / 2 + 1; ks <= vn; ks++)
                    arrA[ks] = a[vn];
            }
            ez = vn + 1;
        }
        pw.println(res);
        for (int num : arrA)
            pw.write(num + " ");
        pw.close();
        f.close();
    }

}
