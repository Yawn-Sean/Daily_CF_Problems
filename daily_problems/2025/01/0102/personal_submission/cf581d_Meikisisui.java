import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static int[][] ax = new int[3][2], ay = new int[3][2];
    private static char[][] g = new char[301][301];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int[] x = new int[3];
        int[] y = new int[3];
        for (int ez = 0; ez < 3; ez++) {
            x[ez] = Integer.parseInt(st.nextToken());
            y[ez] = Integer.parseInt(st.nextToken());
        }
        for (int ez = 0; ez <= 1; ez++) {
            int c = 2, vn = ez ^ 1;
            while (c-- > 0) {
                int ct2 = 2;
                while (ct2-- > 0) {
                    int xs = x[ez] + x[2];
                    int del = Math.abs(y[2] - y[ez]);
                    if (del > 0) {
                        if (xs != Math.max(y[2], y[ez])) {
                            int temp = x[ez];
                            x[ez] = y[ez];
                            y[ez] = temp;
                            continue;
                        }
                        int cx = (y[2] > y[ez]) ? x[ez] : x[2];
                        int ct = 2;
                        while (ct-- > 0) {
                            if (y[vn] == del && x[vn] == cx) {
                                ax[0][1] = x[2];
                                ay[0][1] = y[2];
                                ax[1][0] = x[2];
                                ax[1][1] = x[2] + x[ez];
                                ay[1][1] = y[ez];
                                printA(xs, ez, pw);
                                pw.close();
                                f.close();
                            }
                            int temp = x[vn];
                            x[vn] = y[vn];
                            y[vn] = temp;
                        }
                    } else {
                        int ct = 2;
                        while (ct-- > 0) {
                            if (x[vn] == xs && y[ez] + y[vn] == xs) {
                                ax[0][1] = x[2];
                                ay[0][1] = y[2];
                                ax[1][0] = x[2];
                                ax[1][1] = x[2] + x[ez];
                                ay[1][1] = y[ez];
                                printA(xs, ez, pw);
                                pw.close();
                                f.close();
                            }
                            if (y[vn] == y[ez] && xs + x[vn] == y[ez]) {
                                ax[0][1] = x[2];
                                ay[0][1] = y[2];
                                ax[1][0] = x[2];
                                ax[1][1] = x[2] + x[ez];
                                ay[1][1] = y[ez];
                                printA(y[ez], ez, pw);
                                pw.close();
                                f.close();
                            }
                            int temp = x[vn];
                            x[vn] = y[vn];
                            y[vn] = temp;
                        }
                    }
                    int temp = x[ez];
                    x[ez] = y[ez];
                    y[ez] = temp;
                }
                int temp = x[2];
                x[2] = y[2];
                y[2] = temp;
            }
        }
        pw.println("-1");
        pw.close();
        f.close();
    }

    private static void printA(int len, int ks, PrintWriter pw) {
        pw.println(len);
        char[] ch = {'C', ks != 0 ? 'B' : 'A', ks != 0 ? 'A' : 'B'};
        for (int ez = 0; ez < 2; ez++) {
            for (int x = ax[ez][0]; x < ax[ez][1]; x++) {
                for (int y = ay[ez][0]; y < ay[ez][1]; y++)
                    g[x][y] = ch[ez];
            }
        }
        for (int ez = 0; ez < len; ez++) {
            for (int vn = 0; vn < len; vn++) {
                if (g[ez][vn] == '\0')
                    pw.print(ch[2]);
                else
                    pw.print(g[ez][vn]);
            }
            pw.println();
        }
    }

}
