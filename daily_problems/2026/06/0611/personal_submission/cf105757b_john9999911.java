// 378125951
public class cf105757b_john9999911 {
    class io {}
    static boolean[] notPrime;
    static {
        int M = (int) 1e6 + 7;
        notPrime = new boolean[M];        
        for (int i = 2; i < M; i++) {
            if (notPrime[i])
                continue;
            for (int j = i + i; j < M; j += i) {
                notPrime[j] = true;
            }
        }
    }
    static void solve() {
        int n = io.nextInt();
        int[] res = new int[n];
        int l = 0, r = n - 1;
        while (n > 0) {
            for (int i = 1; i <= n; i++) {
                if (notPrime[n + i]) continue;
                for (int x = i; x <= n; x++) {
                    if (x > n + i - x) break;
                    res[l++] = x;
                    res[r--] = n + i - x;
                }

                n = i - 1;
                break;
            }
            
        }
        for (int x : res) {
            io.print(x + " ");
        }
        io.println();
    }
}
