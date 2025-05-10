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
        if ((n & 1) == 1) {
            pw.println(n / 2 * 3 + 1);
            for (int ez = 2; ez <= n; ez += 2)
                pw.print(ez + " ");
            for (int ez = 1; ez <= n; ez += 2)
                pw.print(ez + " ");
            for (int ez = 2; ez <= n; ez += 2)
                pw.print(ez + " ");
        } else {
            pw.println(n / 2 * 3);
            for (int ez = 1; ez <= n; ez += 2)
                pw.print(ez + " ");
            for (int ez = 2; ez <= n; ez += 2)
                pw.print(ez + " ");
            for (int ez = 1; ez <= n; ez += 2)
                pw.print(ez + " ");
        }
        pw.close();
        br.close();
    }

}
