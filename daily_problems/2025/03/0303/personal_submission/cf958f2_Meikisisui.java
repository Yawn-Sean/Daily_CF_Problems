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
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Integer.parseInt(st.nextToken());
        }
        int[] cnt = new int[m + 1];
        int total = 0, type = 0, res = Integer.MAX_VALUE;
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= m; ez++) {
            cnt[ez] = Integer.parseInt(st.nextToken());
            total += cnt[ez];
            if (cnt[ez] > 0)
                type++;
        }
        m = type;
        type = 0;
        for (int left = 0, right = 0; right < n; ) {
            while (right < n && type < m) {
                cnt[arr[right]]--;
                if (cnt[arr[right]] == 0)
                    type++;
                right++;
            }
            if (type < m)
                break;
            while (type == m && left <= right - 1) {
                res = Math.min(res, right - 1 - left + 1);
                if (cnt[arr[left]] == 0)
                    type--;
                cnt[arr[left++]]++;
            }
        }
        pw.println(res == Integer.MAX_VALUE ? -1 : res - total);
        pw.close();
        br.close();
    }

}
