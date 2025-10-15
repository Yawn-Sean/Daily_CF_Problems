import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] a = new int[n + 1], b = new int[n + 1];
        for (int ez = 1; ez <= n; ez++)
            b[ez] = Integer.parseInt(st.nextToken());
        for (int ez = 1; ez <= n; ez++) {
            int cur = 1;
            while (b[cur] != 0)
                cur++;
            a[ez] = cur;
            b[cur]--;
            for (int vn = 1; vn + k <= cur; vn++)
                b[vn]--;
        }
        for (int ez = 1; ez <= n; ez++)
            pw.print(a[ez] + " ");
        pw.close();
        br.close();
    }

}
