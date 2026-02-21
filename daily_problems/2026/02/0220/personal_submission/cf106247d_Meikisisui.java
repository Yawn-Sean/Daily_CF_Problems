import java.io.*;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("dotak.in")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long k = Long.parseLong(st.nextToken());
        long ans = n + 1;
        for (int ez = 1; ez <= Math.sqrt(n); ez++) {
            if (n % ez == 0) {
                if (ez <= k)
                    ans = Math.max(ans, n + ez);
                if (n / ez <= k)
                    ans = Math.max(ans, n + n / ez);
            }
        }
        pw.println(ans);
        pw.close();
    }

}
