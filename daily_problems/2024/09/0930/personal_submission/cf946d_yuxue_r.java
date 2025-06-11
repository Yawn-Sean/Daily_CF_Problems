import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] dp = new int[k + 1];
        int ans = 0;

        while (n-- > 0) {
            String s = br.readLine();
            List<Integer> idxs = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                if (s.charAt(i) == '1') idxs.add(i);
            }
            int l = idxs.size();

            if (l > 0) {
                int[] saved = new int[l + 1];
                int v = idxs.get(l - 1) - idxs.get(0) + 1;

                ans += v;
                saved[l] = v;

                for (int i = 0; i < l; i++) {
                    for (int j = i; j < l; j++) {
                        saved[l - (j - i + 1)] = Math.max(saved[l - (j - i + 1)], v - (idxs.get(j) - idxs.get(i) + 1));
                    }
                }

                for (int i = k; i > 0; i--) {
                    for (int j = 1; j <= l; j++) {
                        if (i < j) break;
                        dp[i] = Math.max(dp[i], dp[i - j] + saved[j]);
                    }
                }
            }
        }

        System.out.println(ans - dp[k]);
    }
}
