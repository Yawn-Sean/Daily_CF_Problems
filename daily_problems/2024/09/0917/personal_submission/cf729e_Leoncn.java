
public class cf729e_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int s = sc.ni() - 1;
        int[] g = sc.na(n);
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(g[i] == 0 && i!=s){
                cnt ++;
            }else if(g[i]!=0 && i==s){
                ans++;
                g[i] = 0;
            }
        }
        ans += cnt;
        int r = n-1;
        Arrays.sort(g);
        for (int i = 0; i < n; i++) {
            if(g[i] == 0) continue;
            if(i>r) break;
            if(g[i] - g[i-1]>1){
                int dif = g[i] -g[i-1] - 1;
                if(cnt>=dif){
                    cnt -= dif;
                }else {
                    dif -= cnt;
                    cnt = 0;
                    if(dif>= r- i + 1){
                        ans += r-i+1;
                        r = i-1;
                    }else {
                        ans += dif;
                        r = r- dif;
                    }
                }
            }
        }
        out.println(ans);
    }
}
