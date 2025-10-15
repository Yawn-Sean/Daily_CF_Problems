import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a1 = new int[n];
        int[] a2 = new int[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++) {
            a1[ez] = Integer.parseInt(st.nextToken());
            a2[ez] = a1[ez];
        }
        Arrays.sort(a2);
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (a1[ez] == a2[vn])
                    pw.println(vn % 2 == 0 ? "0 " : "1 ");
            }
        }
        pw.close();
        f.close();
    }

}
