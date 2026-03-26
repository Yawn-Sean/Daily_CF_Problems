import java.io.*;
import java.util.*;

public class Main {
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(System.out);
        st.nextToken();
        int t = (int) st.nval;
        while (t-- > 0) {
            st.nextToken();
            int n = (int) st.nval;
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                st.nextToken();
                nums[i] = (int) st.nval;
            }
            int[] pref = nums.clone();
            int[] suff = nums.clone();
            for (int i = 1; i < n; i++) {
                pref[i] = gcd(pref[i], pref[i - 1]);
            }
            for (int i = n - 2; i >= 0; i--) {
                suff[i] = gcd(suff[i], suff[i + 1]);
            }
            int[] ans = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                if (pref[i] == suff[i + 1]) {
                    ans[i] = 1;
                }
            }
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int x : suff) {
                cnt.put(x, 0);
            }
            for (int i = 0; i < n - 2; i++) {
                for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
                    int k = entry.getKey();
                    if (nums[i] % k != 0) {
                        cnt.put(k, entry.getValue() + 1);
                    }
                }
                if (cnt.get(suff[i + 1]) <= 1) {
                    ans[i] = 1;
                }
            }
            cnt.clear();
            for (int x : pref) {
                cnt.put(x, 0);
            }
            for (int i = n - 1; i > 0; i--) {
                for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
                    int k = entry.getKey();
                    if (nums[i] % k != 0) {
                        cnt.put(k, entry.getValue() + 1);
                    }
                }
                if (cnt.get(pref[i - 1]) <= 1) {
                    ans[i - 1] = 1;
                }
            }
            int res = 0;
            for (int x : ans) res += x;
            out.println(res);
        }
        out.flush();
        out.close();
    }
}
