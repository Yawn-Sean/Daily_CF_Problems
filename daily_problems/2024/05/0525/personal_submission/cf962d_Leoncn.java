
public class cf962d_Leoncn {
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
        int[] g = sc.na(n);
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->{
            if(a[0] == b[0]){
                return Long.compare(a[1], b[1]);
            }
            return Long.compare(a[0], b[0]);
        });
        for (int i = 0; i < n; i++) {
            pq.add(new long[]{g[i], i});
        }
        List<long[]> list = new ArrayList<>();
        while (pq.size()>0){
            if(pq.size()>=2){
                long[] p1 = pq.poll();
                long[] p2 = pq.poll();
                if(p1[0] == p2[0]){
                    pq.add(new long[]{p1[0]*2, p2[1] });
                }else {
                    list.add(p1);
                    pq.add(p2);
                }

            }else {
                list.add(pq.poll());
            }
        }
        list.sort((a,b)->Long.compare(a[1],b[1]));
        out.println(list.size());
        for(long[] l : list){
            out.print(l[0] + " ");
        }
        
    }
}
