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
            long n = Long.parseLong(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int x = Math.abs(x1 - x2) + 1, y = Math.abs(y1 - y2) + 1;
            long tmp = (n - x + 1) * (m - y + 1);
            tmp *= 2;
            if (n - x + 1 >= x && m - y + 1 >= y)
                tmp -= (n - x + 1 - x + 1) * (m - y + 1 - y + 1);
            pw.println(n * m - tmp);
        }
        pw.close();
    }

}
