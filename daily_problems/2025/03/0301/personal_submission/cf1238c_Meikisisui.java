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
        int t = Integer.parseInt(st.nextToken());
        int p[] = new int[200005];
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), res = 0;
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++)
                p[ez] = Integer.parseInt(st.nextToken());
            p[n + 1] = 0;
            for (int ez = 2; ez <= n; ez++) {
                if (p[ez] - 1 == p[ez + 1])
                    ez++;
                else
                    res++;
            }
            pw.println(res);
        }
        pw.close();
        br.close();
    }

}
