package daily_problems.2024.04.0413.personal_submission;

public class cf830b_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static int N;
    public static SegmentTree SGT;
    public static long findDiff(int a, int b){
        long total = 0;
        if(b < a){
            total = (N - 1) - a + (b + 1);
            total -= SGT.rmq(a+1, N-1);
            total -= SGT.rmq(0, b);
        } else{
            total = b - a;
            total -= SGT.rmq(a+1, b);
        }
        SGT.update(b, b, 1);
        return total;
    }

    public static void solve() {
        N = sc.ni();

        TreeMap<Integer, TreeSet<Integer>> d = new TreeMap<Integer, TreeSet<Integer>>();

        for(int i = 0; i < N; i++){
            int n = sc.ni();
            if(!d.containsKey(n)) d.put(n, new TreeSet<Integer>());
            d.get(n).add(i);
        }
        SGT = new SegmentTree(new long[N]);
        long total = 0;
        int last = -1;
        for(Integer k : d.keySet()){
            TreeSet<Integer> set = d.get(k);
            Integer a = set.higher(last);
            if(a == null){
                a = set.higher(-1);
            }
            total += findDiff(last, a);

            int cnt = 0;
            while(true){
                set.remove(a);
                Integer b = set.higher(a);
                if(b == null){
                    b = set.higher(-1);
                    if(b == null) break;
                }
                total += findDiff(a, b);
                a = b;
            }
            last = a;
        }
        out.println(total);

    }
}
