import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            long x = Long.valueOf(st.nextToken());
            if (x == 1) {
                pw.println("1");
                pw.println("1");
                continue;
            }
            long n = 1;
            long target = -1;
            while (true) {
                long sum = n * (n + 1) / 2;
                long diff = sum - x;
                if (diff >= 0 && diff % 2 == 0 && sum >= 2 - x) {
                    long cur = diff / 2;
                    if (cur != 1 && (n < 2 || cur != sum - 2)) {
                        target = cur;
                        break;
                    }
                }
                n++;
            }
            pw.println(n);
            boolean[] isFu = new boolean[(int) n + 1];
            long rem = target;
            for (int i = (int) n; i >= 2; i--) {
                if (rem == 0)
                    break;
                if (rem >= i) {
                    if (rem - i == 1)
                        continue;
                    isFu[i] = true;
                    rem -= i;
                }
            }
            if (rem > 0)
                isFu[(int) rem] = true;
            pw.print("1");
            for (int i = 2; i <= n; i++) {
                pw.print(isFu[i] ? "-" : "+");
                pw.print(i);
            }
            pw.println();
        }
        pw.close();
    }

}
