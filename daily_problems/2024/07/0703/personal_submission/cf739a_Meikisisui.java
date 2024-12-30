import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int minLen = Integer.MAX_VALUE;
        while (m > 0) {
            st = new StringTokenizer(f.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            minLen = Math.min(minLen, right - left + 1);
            m--;
        }
        pw.println(minLen);
        int vn = 0;
        for (int ez = 0; ez < n; ez++) {
            pw.print(vn);
            pw.print(' ');
            vn++;
            vn %= minLen;
        }
        pw.close();
    }

}
