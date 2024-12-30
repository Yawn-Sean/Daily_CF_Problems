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
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int ji = 1;
        for (int ez = 1; ez <= n; ez++) {
            b[ez] = Integer.parseInt(st.nextToken());
            ji += b[ez];
        }
        ji %= 2;
        int cnt = 0;
        boolean[] vis = new boolean[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            if (vis[ez])
                continue;
            cnt++;
            int next = ez;
            while (!vis[next]) {
                vis[next] = true;
                next = a[next];
            }
        }
        if (cnt == 1)
            pw.println(ji);
        else
            pw.println(ji + cnt);
        pw.close();
        f.close();
    }

}
