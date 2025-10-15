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
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
        }
        int res = 0, left = 0, right = 0, cnt = 0, start = 0, end = 0;
        for (right = 0; right < n; right++) {
            if (arr[right] == 0)
                cnt++;
            while (cnt > k) {
                if (arr[left] == 0)
                    cnt--;
                left++;
            }
            if (right - left + 1 >= res) {
                res = right - left + 1;
                start = left;
                end = right;
            }
        }
        pw.println(res);
        for (int ez = 0; ez < n; ez++) {
            if (ez >= start && ez <= end) {
                pw.print("1 ");
            } else
                pw.print(arr[ez] + " ");
        }
        pw.close();
        br.close();
    }

}
