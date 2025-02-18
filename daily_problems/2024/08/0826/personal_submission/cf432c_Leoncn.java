
public class cf432c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            g[i]--;
            pos[g[i]] = i;
        }
        boolean[] isPrime = new boolean[100000 + 10];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < isPrime.length; i++) {
            for (int j = i * 2; j < isPrime.length; j += i) {
                isPrime[j] = false;
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            while (true) {
                int wh = pos[i];
                if (wh == i)
                    break;
                int lower = lower(isPrime, wh - i);
                int secondIndex = wh - lower + 1;
                int min = Math.min(wh, secondIndex);
                int max = Math.max(wh, secondIndex);
                swap(wh, secondIndex, g, pos);
                ans.add((min + 1) + " " + (max + 1));
            }
        }
        out.println(ans.size());
        for (String s : ans) {
            out.println(s);
        }
    }
    static void swap(int i, int j, int[] g, int[] pos) {
        int t = g[i];
        g[i] = g[j];
        g[j] = t;
        pos[g[i]] = i;
        pos[g[j]] = j;
    }

    static int lower(boolean[] isPrime, int factLen) {
        if (isPrime[factLen + 1]) {
            return factLen + 1;
        }
        if (factLen % 2 == 1) {
            return 2;
        }
        for (int i = 2;; i++) {
            if (isPrime[i] && isPrime[factLen + 2 - i])
                return i;
        }
    }
}
