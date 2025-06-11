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
        int k = Integer.parseInt(st.nextToken());
        if (k % 2 != 0)
            pw.println("-1");
        else {
            for (int ez = 1; ez <= k; ez++) {
                for (int vn = 1; vn <= k; vn++) {
                    for (int ks = 1; ks <= k; ks++) {
                        if (((vn - 1) / 2 + (ks - 1) / 2 + ez) % 2 == 0)
                            pw.print("b");
                        else
                            pw.print("w");
                    }
                    pw.println();
                }
                pw.println();
            }
        }
        pw.close();
        f.close();
    }

}
