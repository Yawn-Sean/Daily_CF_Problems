import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int res = 0;
            if (n == 1 && m == 1)
                res = 1;
            else if (n == 1 || m == 1)
                res = 2;
            else if (n == m)
                res = 8;
            else
                res = 4;
            pw.println(res);
        }
        pw.close();
    }
}
