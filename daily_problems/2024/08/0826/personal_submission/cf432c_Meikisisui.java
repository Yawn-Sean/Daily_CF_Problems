import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int[] s;
    private static boolean[] prime;
    private static int res;
    private static int[] pathx;
    private static int[] pathy;
    private static int maxn = 100002;

    public static void yuchuli() {
        prime = new boolean[maxn];
        prime[0] = true;
        prime[1] = true;
        for (int i = 2; i < maxn; i++) {
            if (!prime[i]) {
                for (int j = i * 2; j < maxn; j += i)
                    prime[j] = true;
            }
        }
    }

    public static void swap(int x, int y) {
        if (x == y)
            return;
        else if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        for (int i = x; i > y; i--) {
            if (!prime[i - y + 1]) {
                pathx[res] = y;
                pathy[res] = i;
                int temp = s[y];
                s[y] = s[i];
                s[i] = temp;
                y = i;
                res++;
                swap(x, y);
                break;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        yuchuli();
        int n = Integer.parseInt(st.nextToken());
        res = 0;
        s = new int[n + 1];
        pathx = new int[maxn * 5];
        pathy = new int[maxn * 5];
        st = new StringTokenizer(f.readLine());
        for (int i = 1; i <= n; i++)
            s[i] = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            while (s[i] != i)
                swap(s[i], i);
        }
        pw.println(res);
        for (int i = 0; i < res; i++)
            pw.println(pathx[i] + " " + pathy[i]);
        pw.close();
        f.close();
    }

}
