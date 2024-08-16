import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static final int M = 100_005;
    private static int[] R = new int[M];
    private static int[] C = new int[M];
    private static int[] lastR = new int[M];
    private static int[] nextR = new int[M];
    private static int[] lastC = new int[M];
    private static int[] nextC = new int[M];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            R[ez] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            C[ez] = Integer.parseInt(st.nextToken());
        // 预处理R,C每个值前面第一个与其奇偶性相反的数的位置
        // 奇偶性不同则不连通
        int nodd = 0, neve = 0;
        for (int ez = 1; ez <= n; ez++) {
            if ((R[ez] & 1) != 0) {
                nodd = ez;
                lastR[ez] = neve;
            } else {
                neve = ez;
                lastR[ez] = nodd;
            }
        }
        nodd = neve = 0;
        for (int ez = 1; ez <= n; ez++) {
            if ((C[ez] & 1) != 0) {
                nodd = ez;
                lastC[ez] = neve;
            } else {
                neve = ez;
                lastC[ez] = nodd;
            }
        }
        nodd = neve = n + 1;
        for (int ez = n; ez >= 1; ez--) {
            if ((R[ez] & 1) != 0) {
                nodd = ez;
                nextR[ez] = neve;
            } else {
                neve = ez;
                nextR[ez] = nodd;
            }
        }
        nodd = neve = n + 1;
        for (int ez = n; ez >= 1; ez--) {
            if ((C[ez] & 1) != 0) {
                nodd = ez;
                nextC[ez] = neve;
            } else {
                neve = ez;
                nextC[ez] = nodd;
            }
        }

        for (int ez = 0; ez < q; ez++) {
            st = new StringTokenizer(f.readLine());
            int ra = Integer.parseInt(st.nextToken());
            int ca = Integer.parseInt(st.nextToken());
            int rb = Integer.parseInt(st.nextToken());
            int cb = Integer.parseInt(st.nextToken());
            if (R[ra] % 2 != R[rb] % 2)
                pw.println("NO");
            else if (lastR[ra] < rb && rb < nextR[ra] && lastC[ca] < cb && cb < nextC[ca])
                pw.println("YES");
            else
                pw.println("NO");
        }
        pw.close();
        f.close();
    }

}
