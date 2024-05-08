import java.io.PrintWriter;
import java.util.PriorityQueue;

public class cf721d_Leoncn {
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
        int k = sc.ni();
        long x = sc.ni();
        long[] g = sc.nal(n);
        int cnt = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->Long.compare(Math.abs(a[0]), Math.abs(b[0])));
        for (int i = 0; i < n; i++) {
            if(g[i]<0){
                cnt++;
            }
            pq.add(new long[]{g[i],i});
        }
        if((cnt&1)==0){
            long[] p = pq.poll();
            if(p[0]>=0){
                long c = p[0]/ x + 1;
                if(c>k){
                    p[0] -= x*k;
                    k =0;
                }else {
                    p[0] -= x*c;
                    k-=c;
                }
            }else {
                long c = p[0]/ (-x) + 1;
                if(c>k){
                    p[0] += x*k;
                    k =0;
                }else {
                    p[0] += x*c;
                    k-=c;
                }
            }
            g[(int)p[1]] = p[0];
            pq.add(p);
        }
        while (k>0){
            long[] p = pq.poll();
            if(p[0]>=0){
                p[0]+=x;
            }else {
                p[0]-=x;
            }
            g[(int)p[1]] = p[0];
            pq.add(p);
            k--;
        }
        for (int i = 0; i < n; i++) {
            out.print(g[i] + " ");
        }
    }
}
