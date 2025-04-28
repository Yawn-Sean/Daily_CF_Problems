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
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            boolean flag = true;
            if ((a == b && b == c && a % 2 == 1) || (a % 2 == 1 && b % 2 == 1 && c % 2 == 1))
                flag = false;
            int res1 = Math.min(Math.min(a, b), c) + d / 2;
            int res2 = (a / 2) + (b / 2) + (c / 2) + (d / 2) + (!flag ? 1 : 0);
            pw.println(Math.max(res1, res2));
        }
        pw.close();
        br.close();
    }

}
