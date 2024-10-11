import java.util.Arrays;
import java.util.PriorityQueue;

public class cf913d_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int tot = sc.ni();
        int[][] g = new int[n][3];
        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
            g[i][1] = sc.ni();
            g[i][2] = i+1;
        }
        Arrays.sort(g, (a,b)->Integer.compare(b[0],a[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += g[i][1];
            pq.add(-g[i][1]);
            while (cur>tot){
                cur += pq.poll();
            }
            ans = Math.max(ans, Math.min(pq.size(), g[i][0]));
        }
        Arrays.sort(g, (a,b)->Integer.compare(a[1],b[1]));
        out.println(ans);
        out.println(ans);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(cnt<ans&& g[i][0]>=ans){
                out.print(g[i][2] + " " );
                cnt++;
            }
        }
    }
}
