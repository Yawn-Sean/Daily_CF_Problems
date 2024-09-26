import java.util.HashMap;
import java.util.Map;


public class cf975d_Leoncn {
        public static void solve() {
        int n = sc.ni();
        long a = sc.ni();
        long b = sc.ni();
        Map<Long, Integer> cnt1 = new HashMap<>();
        Map<Pair, Integer> cnt2 = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.ni();
            int vx = sc.ni();
            int vy = sc.ni();
            ans += cnt1.getOrDefault(-a * vx + vy, 0);
            ans -= cnt2.getOrDefault(new Pair(vx, vy), 0);

            cnt1.merge(-a * vx + vy,1, Integer::sum);
            cnt2.merge(new Pair(vx, vy),1, Integer::sum);
        }
        out.println(ans*2);
    }
}
