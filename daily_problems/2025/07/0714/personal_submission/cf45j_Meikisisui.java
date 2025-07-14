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
        int m = Integer.parseInt(st.nextToken());
        if (1 == n && 1 == m)
            pw.println("1");
        else if (n + m < 5)
            pw.println("-1");
        else {
            int left = 1, right = 1 + n * m / 2;
            for (int ez = 0; ez < n; ez++) {
                for (int vn = 0; vn < m; vn++) {
                    if ((ez + vn) % 2 == 0)
                        pw.print(right++ + " ");
                    else
                        pw.print(left++ + " ");
                }
                pw.println();
            }
        }
        pw.close();
        br.close();
    }


}
