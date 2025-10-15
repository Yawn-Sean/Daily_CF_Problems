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
        int max = 1_000_000_0;
        int[] prime = new int[max + 1];
        int[] cnt1 = new int[max + 1];
        int[] cnt2 = new int[max + 1];
        for (int i = 2; i <= max; i++) {
            if (prime[i] == 0) {
                for (int j = i; j <= max; j += i) {
                    if (prime[j] == 0)
                        prime[j] = i;
                }
            }
        }
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] nums1 = new int[n];
        int[] nums2 = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            nums1[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++)
            nums2[i] = Integer.parseInt(st.nextToken());
        for (int x : nums1) {
            while (x > 1) {
                cnt1[prime[x]]++;
                x /= prime[x];
            }
        }
        for (int x : nums2) {
            while (x > 1) {
                cnt2[prime[x]]++;
                x /= prime[x];
            }
        }
        // 质因数最小次数
        for (int i = 0; i <= max; i++) {
            cnt1[i] = Math.min(cnt1[i], cnt2[i]);
            cnt2[i] = cnt1[i];
        }
        for (int i = 0; i < n; i++) {
            int x = nums1[i];
            while (x > 1) {
                if (cnt1[prime[x]] > 0) {
                    cnt1[prime[x]]--;
                    nums1[i] /= prime[x];
                }
                x /= prime[x];
            }
        }
        for (int i = 0; i < m; i++) {
            int x = nums2[i];
            while (x > 1) {
                if (cnt2[prime[x]] > 0) {
                    cnt2[prime[x]]--;
                    nums2[i] /= prime[x];
                }
                x /= prime[x];
            }
        }
        pw.println(n + " " + m);
        for (int v : nums1)
            pw.print(v + " ");
        pw.println();
        for (int v : nums2)
            pw.print(v + " ");
        pw.println();
        pw.close();
        br.close();
    }

}
