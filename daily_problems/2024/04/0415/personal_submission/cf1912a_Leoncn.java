package daily_problems.2024.04.0415.personal_submission;

public class cf1912a_Leoncn {
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
        long x = sc.nl();
        int n = sc.ni();
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->Long.compare(b[0],a[0]));
        List<Integer>[] arr = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            int c = sc.ni();
            arr[i] = new ArrayList<>();
            for (int j = 0; j < c; j++) {
                arr[i].add(sc.ni());
            }
        }
        for (int i = 0; i < n; i++) {
            int s = arr[i].size();
            long min = 0; long sum = 0;
            for (int j = 0; j < s; j++) {
                sum +=arr[i].get(j);
                min = Math.min(min, sum);
                if(sum>0){
                    pq.add(new long[]{min, sum, j+1, i});
                    break;
                }
            }
        }
        while (pq.size()>0){
            long[] p = pq.poll();
            if(x+p[0]<0){
                break;
            }
            int w = (int)p[2];
            int i = (int)p[3];
            x += p[1];
            long min = 0; long sum = 0;
            for (int j = w; j < arr[i].size(); j++) {
                sum +=arr[i].get(j);
                min = Math.min(min, sum);
                if(sum>0){
                    pq.add(new long[]{min, sum, j+1, i});
                    break;
                }
            }

        }
        out.println(x);

    }

}
