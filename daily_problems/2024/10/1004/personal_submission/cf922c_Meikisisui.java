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
        long k = Long.parseLong(st.nextToken());
        long i = 1;
        for (; i <= k; i++) {
            if ((n + 1) % i != 0)
                break;
        }
        if (i <= k)
            pw.println("No");
        else
            pw.println("Yes");
        pw.close();
        f.close();
    }

}
