import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 2) {
                if ((m & 1) == 1)
                    pw.println("2 1");
                else
                    pw.println("1 2");
            } else {
                m = Math.min(n, m);
                for (int i = 0; i < m; i++)
                    pw.print(n - i + " ");
                for (int i = 1; i <= n - m; i++)
                    pw.print(i + " ");
                pw.println();
            }
        }
        pw.close();
    }

}
