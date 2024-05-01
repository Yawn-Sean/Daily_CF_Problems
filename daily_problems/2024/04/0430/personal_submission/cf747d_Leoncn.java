public class cf747d_Leoncn {
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
        int[] g = sc.na(n);
        int f = 1;
        int cnt = 0;
        int ans = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = 1;
            if(g[i]<0){
                r = -1;
                k--;
            }
            if(r!=f){
                ans++;
                if(f==1 && cnt!=i){
                    list.add(cnt);
                }
                f = r;
                cnt = 1;
            }else {
                cnt++;
            }
        }
        if(k<0){
            out.println(-1);
            return;
        }
        list.sort(Integer::compareTo);
        for(int l: list){
            if(l>k){
                break;
            }else {
                k-=l;
                ans-=2;
            }
        }
        if(ans>0 && f == 1 && k>=cnt){
            ans--;
        }
        out.println(ans);

    }
}
