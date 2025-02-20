import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int[] arr = new int[k];
        st = new StringTokenizer(br.readLine());
        int sum = 0, large = 0, mid = n / 2 + 1;
        for (int ez = 0; ez < k; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
            sum += arr[ez];
        }
        if (sum + n - k > x) {
            pw.println("-1");
            pw.close();
            br.close();
            return;
        }
        Arrays.sort(arr);
        for (int ez = k - 1; ez >= 0; ez--) {
            if (arr[ez] < y)
                break;
            else
                large++;
        }
        if (k - large > n / 2) {
            pw.println("-1");
            pw.close();
            br.close();
            return;
        }
        // 先都填1
        int add1 = n - k;
        // 剩下 中位数往后填y-1
        int add2 = (mid - large) * (y - 1);
        if (sum + add1 + add2 > x) {
            pw.println("-1");
            pw.close();
            br.close();
            return;
        } else {
            if (mid - large <= 0) {
                // 都打1
                for (int ez = 0; ez < n - k; ez++)
                    pw.print("1 ");
            } else {
                int tmp = mid - large;
                for (int ez = 0; ez < tmp; ez++)
                    pw.print(y + " ");
                tmp = n - k - tmp;
                for (int ez = 0; ez < tmp; ez++)
                    pw.print("1 ");
            }
        }
        pw.close();
        br.close();
    }

}
