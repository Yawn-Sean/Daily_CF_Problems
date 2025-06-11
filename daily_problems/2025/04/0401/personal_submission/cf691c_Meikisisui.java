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
        String s = st.nextToken();
        int n = s.length();
        int start = -1, end = n - 1, point = n;
        // 去掉前后0
        for (int ez = 0; ez < n; ez++) {
            if (s.charAt(ez) > '0' && s.charAt(ez) <= '9') {
                start = ez;
                break;
            }
        }
        for (int ez = n - 1; ez >= 0; ez--) {
            if (s.charAt(ez) > '0' && s.charAt(ez) <= '9') {
                end = ez;
                break;
            }
        }
        for (int ez = 0; ez < n; ez++) {
            if (s.charAt(ez) == '.') {
                point = ez;
                break;
            }
        }
        if (start >= 0) {
            pw.print(s.charAt(start));
            if (end > start)
                pw.print(".");
            for (int ez = start + 1; ez <= end; ez++) {
                if (s.charAt(ez) != '.')
                    pw.print(s.charAt(ez));
            }
            if (start != point - 1) {
                pw.print("E");
                if (start < point)
                    pw.print(point - start - 1);
                else if (start > point)
                    pw.print(point - start);
            }
        } else
            pw.print("0");
        pw.close();
        br.close();
    }

}
