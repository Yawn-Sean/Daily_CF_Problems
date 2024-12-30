public class cf1270d_Leoncn {
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
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int j = 1; j <= k + 1; j++) {
            int[] queryArgs = new int[k];
            int index = 0;
            for (int i = 1; i <= k + 1; i++) {
                if (i != j) {
                    queryArgs[index++] = i;
                }
            }
            int val = query(queryArgs);
            cnt.merge(val, 1, Integer::sum);
        }
        int ans = 0;
        int c = 0;
        for(int a : cnt.keySet()){
            if(a>c){
                c = a;
                ans = cnt.get(a);
            }
        }
        out.println("! " + ans);
    }

    private static int query(int... args) {
        out.print("?");
        for (int arg : args) {
            out.print(" " + arg);
        }
        out.println();
        out.flush();
        int idx = sc.ni();
        int val = sc.ni();
        return val;
    }
}
