import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long p = Long.parseLong(st.nextToken());
        long q = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        boolean valid = true;
        while (n > 0) {
            long a = Long.parseLong(st.nextToken());
            if (q == 0 || a > p / q) {
                valid = false;
                break;
            }
            long temp = q;
            q = p - a * q;
            p = temp;
            n--;
        }
        if (!valid || q != 0)
            pw.println("NO");
        else
            pw.println("YES");
        pw.close();
        f.close();
    }

}
