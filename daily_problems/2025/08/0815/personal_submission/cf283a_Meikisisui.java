import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long sum = 0;
        int cnt = 1;
        long[] wei = new long[n + 1], arr = new long[n + 1];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            if (1 == t) {
                int a = Integer.parseInt(st.nextToken());
                long x = Long.parseLong(st.nextToken());
                wei[a - 1] += x;
                sum += x * a;
            } else if (2 == t) {
                long k = Long.parseLong(st.nextToken());
                arr[cnt] += k;
                cnt++;
                sum += k;
            } else if (3 == t) {
                cnt--;
                sum -= arr[cnt] + wei[cnt];
                wei[cnt - 1] += wei[cnt];
                wei[cnt] = 0;
            }
            pw.println(sum / (double) cnt);
        }
        pw.close();
    }

}
