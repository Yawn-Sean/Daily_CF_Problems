import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            char[][] ch = new char[n + 1][m + 1];
            // x+y最大值, x+y最小值, x-y最大值, x-y最小值
            int n1 = Integer.MIN_VALUE, n2 = Integer.MAX_VALUE,
                    n3 = Integer.MIN_VALUE, n4 = Integer.MAX_VALUE;
            int[] p1 = new int[2], p2 = new int[2], p3 = new int[2], p4 = new int[2];
            for (int ez = 1; ez <= n; ez++) {
                st = new StringTokenizer(br.readLine());
                ch[ez] = st.nextToken().toCharArray();
                for (int vn = 1; vn <= m; vn++) {
                    if ('B' == ch[ez][vn - 1]) {
                        int dx = ez + vn;
                        int dy = ez - vn;
                        if (n1 < dx) {
                            n1 = dx;
                            p1[0] = ez;
                            p1[1] = vn;
                        }
                        if (n2 > dx) {
                            n2 = dx;
                            p2[0] = ez;
                            p2[1] = vn;
                        }
                        if (n3 < dy) {
                            n3 = dy;
                            p3[0] = ez;
                            p3[1] = vn;
                        }
                        if (n4 > dy) {
                            n4 = dy;
                            p4[0] = ez;
                            p4[1] = vn;
                        }
                    }
                }
            }
            // 所有点到这四个点曼哈顿距离的最大值的最小值
            int minDis = Integer.MAX_VALUE, resX = 0, resY = 0;
            for (int ez = 1; ez <= n; ez++) {
                for (int vn = 1; vn <= m; vn++) {
                    int maxDis = 0;
                    maxDis = Math.max(maxDis, Math.abs(ez - p1[0]) + Math.abs(vn - p1[1]));
                    maxDis = Math.max(maxDis, Math.abs(ez - p2[0]) + Math.abs(vn - p2[1]));
                    maxDis = Math.max(maxDis, Math.abs(ez - p3[0]) + Math.abs(vn - p3[1]));
                    maxDis = Math.max(maxDis, Math.abs(ez - p4[0]) + Math.abs(vn - p4[1]));
                    if (maxDis < minDis) {
                        minDis = maxDis;
                        resX = ez;
                        resY = vn;
                    }
                }
            }
            pw.println(resX + " " + resY);
        }
        pw.close();
        br.close();
    }

}
