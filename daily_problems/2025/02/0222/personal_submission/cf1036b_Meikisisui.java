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
        int q = Integer.parseInt(st.nextToken());
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());
            if (n > k || m > k) {
                pw.println("-1");
                continue;
            }
            long jiou = (n + m) % 2;
            if (jiou == 0) {
                if (k % 2 == Math.max(n, m) % 2)
                    pw.println(k);
                else
                    pw.println(k - 2);
            } else
                pw.println(k - 1);
        }
        pw.close();
        br.close();
    }

}
