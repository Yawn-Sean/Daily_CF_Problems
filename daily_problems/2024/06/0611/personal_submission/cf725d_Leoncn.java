
public class cf725d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        long x = sc.nl();
        long y = sc.nl();
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->Long.compare(b[0],a[0]));
        PriorityQueue<long[]> pq1 = new PriorityQueue<>((a,b)->
            Long.compare( a[1]-a[0] , (b[1] - b[0]))
        );

        for (int i = 0; i < n-1; i++) {
            long a = sc.nl();
            long b = sc.nl();
            if(a<=x){
                pq.add(new long[]{a,b});
            }else {
                pq1.add(new long[]{a,b});
            }
        }
        int ans  = pq1.size()+1;
        while (pq1.size()>0 && x>0){
            long[] p = pq1.poll();
            long d = p[1] - p[0]+1;
            if(d>x){
                break;
            }
            x-=d;
            while (pq.size()>0 && pq.peek()[0]>x){
                pq1.add(pq.poll());
            }
            ans = Math.min(pq1.size()+1 ,ans);
        }
        out.println(ans);

    }
}
