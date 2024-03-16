import java.util.*;
import java.io.*;
public class cf665d_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] a = na();

        // 筛素数
        int MAX = (int) 1e6 * 2;
        boolean[] isPrime = new boolean[MAX + 1];
        int idx = 0;
        Arrays.fill(isPrime, 2, MAX + 1, true);

        int[] primes = new int[MAX + 1]; // 用数组存素数
        for (int i = 2; i < MAX + 1; i++) { // 欧拉筛 数组版
            if (isPrime[i]) primes[idx++] = i;
            for (int k = 0; k < idx; k++) {
                int j = primes[k];
                if (i * j > MAX) break;
                isPrime[i * j] = false;
                if (i % j == 0) break;
            }
        }

        List<Integer> ans = new ArrayList<>();
        int cnt = 0;
        for (int v: a) {
            if (v == 1) cnt++;
        }
        if (cnt > 1) { // 1+1为素数，可以重复取多个，有多个1，此时肯定是包含1的为结果，再找有没有+1为素数的数（找一个）
            for (int i = 0; i < cnt; i++) {
                ans.add(1);
            }
            for (int v: a) {
                if (v == 1) continue;
                if (isPrime[v + 1]) {
                    ans.add(v);
                    break;
                }
            }
        } else {
            out: for (int i = 0; i < n; i++) { // 找到一对和为素数的元组，直接break，不可能有第三个数(why?)
                for (int j = i + 1; j < n; j++) {
                    if (isPrime[a[i] + a[j]]) {
                        ans.add(a[i]);
                        ans.add(a[j]);
                        break out;
                    }
                }
            }
        }
        if (ans.isEmpty()) ans.add(a[0]); // 无满足条件，任取
        out.println(ans.size());
        for (int v: ans) {
            out.print(v + " ");
        }
        out.flush();
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int n = in.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Integer.parseInt(in[i]);
        }
        return ans;
    }
}
