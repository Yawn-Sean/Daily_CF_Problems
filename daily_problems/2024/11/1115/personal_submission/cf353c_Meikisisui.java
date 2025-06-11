import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] a = new long[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        long res = 0, sum = 0;
        for (int ez = 0; ez < n; ez++) {
            if (s.charAt(ez) == '1') {
                if (sum > a[ez]) {
                    res += sum;
                    sum = a[ez];
                } else
                    res += a[ez];
            } else
                sum += a[ez];
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
