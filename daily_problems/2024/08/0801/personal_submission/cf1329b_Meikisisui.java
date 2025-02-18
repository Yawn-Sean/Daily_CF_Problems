import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        while (n > 0) {
            st = new StringTokenizer(f.readLine());
            int d = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            long res = 1;
            for (int ez = 1; ez <= d; ez <<= 1)
                res = res * (Math.min(d + 1, ez << 1) - ez + 1) % m;
            pw.println((res + m - 1) % m);
            n--;
        }
        pw.close();
        f.close();
    }

}
