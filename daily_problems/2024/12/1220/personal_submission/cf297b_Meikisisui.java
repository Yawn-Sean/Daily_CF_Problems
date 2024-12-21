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
        int k = Integer.parseInt(st.nextToken());
        int[] alice = new int[n + 1];
        int[] bob = new int[m + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            alice[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= m; ez++)
            bob[ez] = Integer.parseInt(st.nextToken());
        Arrays.sort(alice, 1, n + 1);
        Arrays.sort(bob, 1, m + 1);
        while (m > 0 && n > 0 && alice[n] <= bob[m]) {
            m--;
            n--;
        }
        if (n > 0 && (m == 0 || alice[n] > bob[m]))
            pw.print("YES");
        else
            pw.print("NO");
        pw.close();
        f.close();
    }

}
