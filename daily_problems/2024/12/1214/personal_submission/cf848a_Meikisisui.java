import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int k = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < 26; ez++) {
            int tmp = 1;
            while (k >= (tmp * (tmp - 1) / 2))
                tmp++;
            k -= (tmp - 2) * (tmp - 1) / 2;
            for (int vn = 1; vn < tmp; vn++)
                pw.print((char) ('a' + ez));
            if (0 == k)
                break;
        }
        pw.close();
        f.close();
    }

}
