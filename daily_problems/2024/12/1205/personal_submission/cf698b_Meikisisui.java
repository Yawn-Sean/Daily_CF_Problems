import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static int[] fa;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n + 1];
        fa = new int[n + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        for (int ez = 1; ez <= n; ez++)
            fa[ez] = ez;
        int tmp = 0, p1 = 0, p2 = 0, res = 0;
        for (int ez = 1; ez <= n; ez++) {
            p1 = find(ez);
            p2 = find(a[ez]);
            if (p1 != p2)
                fa[p1] = p2;
            if (tmp == 0 && a[ez] == ez)
                tmp = ez;
        }
        if (tmp == 0) {
            for (int ez = 1; ez <= n; ez++) {
                if (fa[ez] == ez) {
                    tmp = ez;
                    break;
                }
            }
        }
        for (int ez = 1; ez <= n; ez++) {
            if (fa[ez] == ez && a[ez] != tmp) {
                a[ez] = tmp;
                res++;
            }
        }
        pw.println(res);
        for (int ez = 1; ez <= n; ez++)
            pw.print(a[ez] + " ");
        pw.close();
        f.close();
    }

    private static int find(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

}
