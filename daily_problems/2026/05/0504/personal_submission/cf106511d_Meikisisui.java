import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int res = 0;
        for (int i = 0; i < 10; i++) {
            long now = i;
            if (now == 0)
                now = 10;
            while (now <= n) {
                res++;
                now = now * 10 + i;
            }
        }
        pw.println(res);
        pw.close();
    }
}
