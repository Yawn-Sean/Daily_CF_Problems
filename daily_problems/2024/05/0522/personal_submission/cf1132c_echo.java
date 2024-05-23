import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]), q = Integer.parseInt(s[1]);
        int[] ls = new int[q], rs = new int[q];
        for (int i = 0; i < q; i++) {
            String[] lr = br.readLine().split(" ");
            ls[i] = Integer.parseInt(lr[0]);
            rs[i] = Integer.parseInt(lr[1]);
        }
        int[] cnt = new int[n + 1], preSum = new int[n + 1];
        for (int i = 0; i < q; i++) {
            for (int j = ls[i]; j <= rs[i]; j++) {
                cnt[j]++;
            }
        }
        int ans = 0;
        for (int l = 0; l < q; l++) {
            for (int i = ls[l]; i <= rs[l]; i++) {
                cnt[i]--;
            }
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                preSum[i] = preSum[i - 1];
                if (cnt[i] > 0) sum++;
                if (cnt[i] == 1) preSum[i] += 1;
            }
            for (int i = 0; i < q; i++) {
                if (i == l) continue;
                int left = ls[i], right = rs[i];
                ans = Math.max(ans, sum - (preSum[right] - preSum[left - 1]));
            }
            for (int i = ls[l]; i <= rs[l]; i++) {
                cnt[i]++;
            }
        }
        System.out.println(ans);
    }

}
