import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long res = 0;
        for (long i = 1; ceng(i) <= n; i++) {
            if ((n - ceng(i)) % 3 == 0)
                res++;
        }
        pw.println(res);
        pw.close();
    }

    private static long ceng(long i) {
        return (i * 3 + 1) * i / 2;
    }

}
