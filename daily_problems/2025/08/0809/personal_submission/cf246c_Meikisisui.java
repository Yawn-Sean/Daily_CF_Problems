import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] a = new int[n];
        for (int ez = 0; ez < n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        Arrays.sort(a);
        for (int len = 1; len <= n; len++) {
            for (int ez = 0; ez <= n - len; ez++) {
                pw.print(len);
                for (int vn = n - 1, tmpLen = 1; vn > ez && tmpLen < len; tmpLen++, vn--)
                    pw.print(" " + a[vn]);
                pw.println(" " + a[ez]);
                k--;
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }
        pw.close();
    }

}
