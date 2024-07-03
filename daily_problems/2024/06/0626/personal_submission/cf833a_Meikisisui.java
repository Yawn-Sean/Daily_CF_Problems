import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(f.readLine());
        while (n > 0) {
            StringTokenizer st = new StringTokenizer(f.readLine());
            long a1 = Long.parseLong(st.nextToken());
            long a2 = Long.parseLong(st.nextToken());
            long t = a1 * a2;
            long left = 0, right = 1_000_001;
            boolean isYes = false;
            while (left + 1 < right) {
                long mid = (left + right) / 2;
                long mid3 = mid * mid * mid;
                if (mid3 == t) {
                    if (a1 % mid == 0 && a2 % mid == 0)
                        isYes = true;
                    break;
                } else if (mid3 > t)
                    right = mid;
                else
                    left = mid;
            }
            if (isYes)
                pw.println("Yes");
            else
                pw.println("No");
            n--;
        }
        pw.close();
    }

}
