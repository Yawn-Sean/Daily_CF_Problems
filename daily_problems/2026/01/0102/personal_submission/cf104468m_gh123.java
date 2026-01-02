
import java.util.*;

public class Main {
    static final long MOD = 1000000007L;
    static final int M = 200_000;

    static long modPow(long a, long e) {
        long res = 1;
        a %= MOD;
        while (e > 0) {
            if ((e & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        long[] f = new long[M + 1];
        long[] g = new long[M + 1];

        f[0] = 1;
        for (int i = 1; i <= M; i++) f[i] = (i * f[i - 1]) % MOD;

        g[M] = modPow(f[M], MOD - 2);
        for (int i = M; i >= 1; i--) g[i - 1] = (i * g[i]) % MOD;

        int t = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int[] pos = new int[Math.max(0, n - 1)];
            Arrays.fill(pos, 1);
            for (int i = 0; i < k; i++) {
                int idx = sc.nextInt();
                idx--; 
                if (idx >= 0 && idx < pos.length) pos[idx] = 0;
            }

            long ans = f[n];
            int cur = 1;
            for (int x : pos) {
                if (x == 1) cur += x;
                else {
                    ans = (ans * g[cur]) % MOD;
                    cur = 1;
                }
            }
            ans = (ans * g[cur]) % MOD;
            sb.append(ans).append('\n');
        }
        sc.close();
        System.out.print(sb.toString());
    }

   
  
}
