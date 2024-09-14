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
        long n = Long.parseLong(st.nextToken());
        long res = 1, t1 = 1, t2 = 2, t3 = t1 + t2;
        while (t3 <= n) {
            t1 = t2;
            t2 = t3;
            t3 = t1 + t2;
            res++;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
