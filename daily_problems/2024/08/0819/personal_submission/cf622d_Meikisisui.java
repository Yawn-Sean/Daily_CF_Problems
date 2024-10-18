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
        int n = Integer.parseInt(st.nextToken());
        int[] res = new int[n * 2];
        int temp = 1;
        for (int ez = 0; temp <= n; ez++, temp += 2) {
            res[ez] = temp;
            res[n - ez - 1] = temp;
        }
        temp = 2;
        for (int ez = n, vn = 0; temp <= n; vn++, temp += 2) {
            res[ez + vn] = temp;
            res[2 * n - 2 - vn] = temp;
        }
        res[2 * n - 1] = n;
        for (int ez = 0; ez < 2 * n; ez++)
            pw.print(res[ez] + " ");
        pw.close();
        f.close();
    }

}
