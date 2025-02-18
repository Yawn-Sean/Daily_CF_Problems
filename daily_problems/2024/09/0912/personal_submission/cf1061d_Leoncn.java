import java.util.Arrays;
import java.util.PriorityQueue;

public class cf1061d_Leoncn {
        public static void solve() {
        int n = sc.ni();
        long x = sc.ni();
        long y = sc.ni();
        int[][] g = sc.nmi(n,2);
        long ans = 0;
        long mod = (long)1e9+7;
        Arrays.sort(g,(a,b)->Integer.compare(a[0],b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(b,a));
        PriorityQueue<Integer> tem = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            int a = g[i][0];
            int b = g[i][1];
            while (tem.size()>0 && tem.peek()<a){
                pq.add(tem.poll());
            }
            if(pq.size()==0){
                ans += x + y *(b -a);
            }else {
                if( y*(a - pq.peek()) <x){
                    ans += y * (a- pq.poll()) + y *(b -a);
                }else {
                    ans += x + y *(b -a);
                }
            }
            tem.add(b);
            ans %= mod;
        }
        out.println(ans);
    }

}
