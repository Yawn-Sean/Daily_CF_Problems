public class cf645d_Leoncn {
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
        int m = sc.ni();
        int[][] arr = sc.nmi(m,2);

        int left = 0, right = m+1;
        while (left<right){
            int mid = left + right>>1;
            if(judge(arr, mid, n)){
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        out.println(left == m+1 ?-1: left);
    }

    private static boolean judge(int[][] arr, int mid, int n){
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int[] cnt = new int[n];
        for (int i = 0; i <mid; i++) {
            int a = arr[i][0] - 1;
            int b = arr[i][1] - 1;
            g[a].add(b);
            cnt[b]++;
        }
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            if(cnt[i] == 0){
                dq.add(i);
            }
        }
        while (dq.size()>0){
            if(dq.size()>1){
                return false;
            }
            int p = dq.poll();
            for(int w: g[p]){
                if(--cnt[w] == 0){
                    dq.add(w);
                }
            }
        }
        return true;
    }
}
