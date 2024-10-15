import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        if (a < b)
            pw.println("-1");
        else if (a == b)
            pw.println(b);
        else {
            double k1 = Math.floor((double) (a - b) / 2 / b);
            double k2 = Math.floor((double) (a + b) / 2 / b);
            double res = Math.min((a - b) / k1 / 2, (a + b) / k2 / 2);
            pw.println(res);
        }
        pw.close();
        f.close();
    }

}
