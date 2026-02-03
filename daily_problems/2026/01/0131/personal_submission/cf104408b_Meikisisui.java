import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            long x1 = Long.parseLong(st.nextToken());
            long y1 = Long.parseLong(st.nextToken());
            long x2 = Long.parseLong(st.nextToken());
            long y2 = Long.parseLong(st.nextToken());
            double res = 0;
            if (x1 == 0 && x2 == 0)
                res = Math.abs(y2 - y1);
            else if (y1 == 0 && y2 == 0)
                res = Math.abs(x2 - x1);
            else {
                long k1 = Math.abs(x1 + y1), k2 = Math.abs(x2 + y2);
                long min = Math.min(k1, k2);
                res = Math.abs(k1 - k2) + Math.PI * min / 2;
            }
            pw.println(res);
        }
        pw.close();
    }

}
