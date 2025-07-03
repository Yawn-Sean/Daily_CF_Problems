import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long b = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long c = Long.parseLong(st.nextToken());
        long res = 0;
        if (b - c > a || n < b) {
            res = n / a;
        } else {
            res = 1 + (n - b) / (b - c);
            n -= res * (b - c);
            if (b - c <= a)
                res += n / a;
        }
        pw.println(res);
        pw.close();
        br.close();
    }

}
