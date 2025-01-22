import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (b == 0)
                pw.print(1);
            else if (a == 0)
                pw.print(0.5);
            else if (b * 4 >= a)
                pw.print(0.5 + (double) a / (16 * b));
            else if (4 * b < a)
                pw.print(1 - (double) b / a);
            pw.println();
        }
        pw.close();
        f.close();
    }

}
