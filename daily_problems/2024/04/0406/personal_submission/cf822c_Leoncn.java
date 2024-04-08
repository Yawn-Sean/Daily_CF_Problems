import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.PriorityQueue;

public class cf822c_Leoncn {
        static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int x = sc.ni();
        int[][] g = sc.nmi(n, 3);
        Arrays.sort(g, Comparator.comparingInt(a -> a[0]));
        int ans = Integer.MAX_VALUE;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            while (pq.size()>0 && pq.peek()[1]<g[i][0]){
                int[] poll = pq.poll();
                int dis = poll[1] - poll[0]+1;
                int v = map.getOrDefault(dis, Integer.MAX_VALUE);
                map.put(dis, Math.min(v, poll[2]));
            }
            int d = g[i][1] -g[i][0]+1;
            if(map.containsKey(x -d)){
                ans = Math.min(map.get(x-d) + g[i][2], ans);
            }
            pq.add(g[i]);
        }
        out.println(ans == Integer.MAX_VALUE?-1:ans);

    }
}
