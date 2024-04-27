public class cf749d_Leoncn {
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
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            g[i].add(0);
        }
        for (int i = 0; i < n; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni();
            g[a].add(b);
        }
        int[][] maxValue = new int[n][2];
        for (int i = 0; i < n; i++) {
            maxValue[i][0] = g[i].get(g[i].size()-1);
            maxValue[i][1] = i;
        }
        Arrays.sort(maxValue, (a,b)->Integer.compare(b[0],a[0]));
        int q = sc.ni();
        while (q-->0){
            int s = sc.ni();
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < s; i++) {
                set.add(sc.ni()-1);
            }
            int maxLoc = -1, secondV = 0;
            for (int i = 0; i < n; i++) {
                if(!set.contains(maxValue[i][1])){
                    if(maxLoc == -1){
                        maxLoc = maxValue[i][1];
                    }else {
                        secondV = maxValue[i][0];
                        break;
                    }
                }
            }
            int res = maxLoc == -1?-1:binaryS(secondV, g[maxLoc]);
            if(res==-1){
                out.println(0 + " " + 0);
            }else {
                out.println(maxLoc + 1 + " " + res);
            }


        }
    }
    private static int binaryS(int v, List<Integer> arr){
        int l = 0, r = arr.size();
        while (l < r){
            int mid = l + r >> 1;
            if(arr.get(mid)<=v){
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        return l == arr.size() ? -1: arr.get(l);
    }

}
