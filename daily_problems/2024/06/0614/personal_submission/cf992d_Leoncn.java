public class cf992d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        long[] g = sc.nal(n);
        int[] nextP = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += g[i];
        }
        for (int i = n-1; i >=0 ; i--) {
            nextP[i] = (i<n-1 && g[i] == 1 ? nextP[i+1]: i);
        }
        sum *= k;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int pt = i;
            long p = 1, s = 0;
            while (pt<n){
                if(nextP[pt] != pt){
                    if(p%k== 0 && p/k - s >0 && p / k - s <= nextP[pt] - pt){
                        ans++;
                    }
                    s += nextP[pt] - pt;
                    pt = nextP[pt];
                }else {
                    if(sum/ g[pt] < p) break;
                    p*= g[pt];
                    s += g[pt];
                    if(p == s*k ){
                        ans++;
                    }
                    pt+=1;
                }
            }
        }
        out.println(ans);
    }
}
