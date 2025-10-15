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
        long[] s = new long[n + 1];
        long[] g = new long[n + 1];
        long[] sumArr = new long[n + 2];
        long sum = 0;
        sumArr[0] = sumArr[n + 1] = Long.MAX_VALUE / 10;
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(br.readLine());
            s[ez] = Long.parseLong(st.nextToken());
            g[ez] = Long.parseLong(st.nextToken());
            sumArr[ez] = s[ez] + g[ez];
        }
        for (int ez = 1; ez <= n; ez++) {
            sumArr[ez] = Math.min(s[ez] + g[ez], Math.min(sumArr[ez - 1] + 1, sumArr[ez + 1] + 1));
            if (sumArr[ez] < s[ez]) {
                pw.println("-1");
                pw.close();
                br.close();
                return;
            }
        }
        for (int ez = n; ez >= 1; ez--) {
            sumArr[ez] = Math.min(s[ez] + g[ez], Math.min(sumArr[ez - 1] + 1, sumArr[ez + 1] + 1));
            if (sumArr[ez] < s[ez]) {
                pw.println("-1");
                pw.close();
                br.close();
                return;
            }
        }
        for (int ez = 1; ez <= n; ez++)
            sum += sumArr[ez] - s[ez];
        pw.println(sum);
        for (int ez = 1; ez <= n; ez++)
            pw.print(sumArr[ez] + " ");
        pw.close();
        br.close();
    }

}
