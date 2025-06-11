public class cf570c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int c = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(cs[i] == '.'){
                c++;
            }else {
                ans += Math.max(0,c-1);
                c = 0;
            }
        }
        ans += Math.max(0,c-1);
        while (q-->0){
            int l = sc.ni() - 1;
            char a = sc.nc();
            if(a == '.'){
                if(cs[l] !='.'){
                    if(l-1>=0 && cs[l-1] == '.'){
                        ans++;
                    }
                    if(l+1<n && cs[l+1] == '.'){
                        ans++;
                    }
                }
            }else {
                if(cs[l] == '.'){
                    if(l-1>=0 && cs[l-1] == '.'){
                        ans--;
                    }
                    if(l+1<n && cs[l+1] == '.'){
                        ans--;
                    }
                }
            }
            cs[l] = a;
            out.println(ans);
        }
    }
}
