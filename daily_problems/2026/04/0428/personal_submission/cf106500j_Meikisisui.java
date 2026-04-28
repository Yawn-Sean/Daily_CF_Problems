import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long b = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long c = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long d = Long.parseLong(st.nextToken());
        long res = 0;
        if (a == b) {
            if (c == d) {
                long tmp = 2 * c / (2 * a + 1);
                res = c - a * tmp;
            }
        } else {
            if ((d - c) % (b - a) == 0) {
                long tmp = (d - c) / (b - a);
                if (tmp >= 0 && c - a * tmp >= (tmp + 1) / 2)
                    res = c - a * tmp;
            }
        }
        pw.println(res);
        pw.close();
    }
}
