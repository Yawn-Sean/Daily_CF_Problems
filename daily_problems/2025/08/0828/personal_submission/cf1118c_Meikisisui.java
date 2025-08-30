import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] cnt = new int[1001];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n * n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            cnt[now]++;
        }
        int[][] res = new int[n][n];
        // 四个角
        for (int ez = 0; ez < n / 2; ez++) {
            for (int vn = 0; vn < n / 2; vn++) {
                for (int value = 1; value <= 1000; value++) {
                    if (cnt[value] >= 4) {
                        res[ez][vn] = value;
                        res[ez][n - 1 - vn] = value;
                        res[n - 1 - ez][vn] = value;
                        res[n - 1 - ez][n - 1 - vn] = value;
                        cnt[value] -= 4;
                        break;
                    }
                }
            }
        }
        // 中轴中心
        if (n % 2 == 1) {
            for (int ez = 0; ez < n / 2; ez++) {
                for (int value = 1; value <= 1000; value++) {
                    if (cnt[value] >= 2) {
                        res[ez][n / 2] = value;
                        res[n - 1 - ez][n / 2] = value;
                        cnt[value] -= 2;
                        break;
                    }
                }
            }
            for (int vn = 0; vn < n / 2; vn++) {
                for (int value = 1; value <= 1000; value++) {
                    if (cnt[value] >= 2) {
                        res[n / 2][vn] = value;
                        res[n / 2][n - 1 - vn] = value;
                        cnt[value] -= 2;
                        break;
                    }
                }
            }
            for (int value = 1; value <= 1000; value++) {
                if (cnt[value] > 0) {
                    res[n / 2][n / 2] = value;
                    cnt[value]--;
                    break;
                }
            }
        }
        for (int ez = 0; ez < 1001; ez++) {
            if (cnt[ez] > 0) {
                pw.println("NO");
                pw.close();
                return;
            }
        }
        pw.println("YES");
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (vn == n - 1)
                    pw.print(res[ez][vn]);
                else
                    pw.print(res[ez][vn] + " ");
            }
            pw.println();
        }
        pw.close();
    }

}
