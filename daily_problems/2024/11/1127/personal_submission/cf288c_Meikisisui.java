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
        int[] res = new int[n + 1];
        boolean used[] = new boolean[n + 1];
        int mask = (1 << 20) - 1;
        for (int ez = n; ez >= 0; ez--) {
            while ((mask ^ ez) > n || used[mask ^ ez])
                mask = mask >> 1;
            res[ez] = mask ^ ez;
            used[mask ^ ez] = true;
        }
        long score = n;
        score = score * (score + 1);
        pw.println(score);
        for (int ez = 0; ez < n + 1; ez++)
            pw.print(res[ez] + " ");
        pw.close();
        f.close();
    }

}
