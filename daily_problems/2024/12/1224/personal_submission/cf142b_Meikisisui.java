import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int res = getKnight(n, m);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int getKnight(int n, int m) {
        if (n > m)
            return getKnight(m, n);
        if (n == 1)
            return m;
        if (n == 2) {
            int kuai = m / 4 * 4, yu = m % 4;
            if (yu > 1)
                return kuai + 4;
            return kuai + yu * 2;
        }
        return (m * n + 1) / 2;
    }

}
