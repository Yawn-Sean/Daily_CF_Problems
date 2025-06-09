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
        int[] arr = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++)
            arr[ez] = Integer.parseInt(st.nextToken());
        if (n < 3 || n % 2 == 0) {
            pw.println(-1);
            pw.close();
            br.close();
            return;
        }
        int cnt = 0;
        for (int ez = n; ez >= 1; ez--) {
            if ((ez & 1) == 1) {
                while (arr[ez] > 0) {
                    arr[ez]--;
                    arr[ez - 1]--;
                    arr[(ez - 1) / 2]--;
                    cnt++;
                }
            } else {
                while (arr[ez] > 0) {
                    arr[ez]--;
                    arr[ez / 2]--;
                    arr[ez + 1]--;
                    cnt++;
                }
            }
        }
        pw.println(cnt);
        pw.close();
        br.close();
    }

}
