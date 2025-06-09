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
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int cnt[] = new int[10];
        boolean isOk = false;
        int sum = 0;
        for (int ez = 0; ez < n; ez++) {
            int now = Integer.parseInt(st.nextToken());
            cnt[now]++;
            sum += now;
        }
        if (sum % 3 == 1 && cnt[0] > 0) {
            if (cnt[1] + cnt[4] + cnt[7] >= 1) {
                for (int ez = 1; ez < 9; ez += 3) {
                    if (cnt[ez] > 0) {
                        cnt[ez]--;
                        sum -= ez;
                        isOk = true;
                        break;
                    }
                }
            } else if (cnt[2] + cnt[5] + cnt[8] > 1) {
                int k = 2;
                for (int ez = 2; ez < 9; ez += 3) {
                    while (cnt[ez] > 0 && k > 0) {
                        sum -= ez;
                        cnt[ez]--;
                        isOk = true;
                        k--;
                    }
                }
            }
        } else if (sum % 3 == 2 && cnt[0] > 0) {
            if (cnt[2] + cnt[5] + cnt[8] >= 1) {
                for (int ez = 2; ez < 9; ez += 3) {
                    if (cnt[ez] > 0) {
                        cnt[ez]--;
                        sum -= ez;
                        isOk = true;
                        break;
                    }
                }
            } else if (cnt[1] + cnt[4] + cnt[7] > 1) {
                int k = 2;
                for (int ez = 1; ez < 9; ez += 3) {
                    while (cnt[ez] > 0 && k > 0) {
                        cnt[ez]--;
                        sum -= ez;
                        isOk = true;
                        k--;
                    }
                }
            }
        } else if (sum % 3 == 0 && cnt[0] > 0)
            isOk = true;
        if (isOk) {
            if (sum == 0)
                pw.println("0");
            else
                for (int ez = 9; ez >= 0; ez--) {
                    while (cnt[ez] > 0) {
                        pw.print(ez);
                        cnt[ez]--;
                    }
                }
        } else
            pw.println("-1");
        pw.close();
        br.close();
    }

}
