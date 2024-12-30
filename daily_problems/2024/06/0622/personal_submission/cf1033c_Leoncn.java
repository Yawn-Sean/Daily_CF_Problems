
public class cf1033c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        boolean[] ans = new boolean[n];
        int[] pos = new int[n+1];
        for (int i = 0; i < n; i++) {
            pos[g[i]] = i;
        }
        ans[pos[n]] = true;
        out:for (int i = n-1; i >0; i--) {
            int p = pos[i];
            for (int j = i; j <=n; j+=i) {
                int l = p-j;
                int r = p+j;
                if(l>=0){
                    if(g[l]>i && ans[pos[g[l]]]){
                        continue out;
                    }
                }
                if(r<n){
                    if(g[r]>i && ans[pos[g[r]]]){
                        continue out;
                    }
                }
            }
            ans[p] = true;
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i]?"B":"A");
        }
    }
}
