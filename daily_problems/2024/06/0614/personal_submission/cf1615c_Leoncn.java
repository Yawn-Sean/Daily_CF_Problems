public static void solve() {
    int n = sc.ni();
    char[] cs = sc.ns().toCharArray();
    char[] tar = sc.ns().toCharArray();
    int cnt = 0;
    int x =0 , y = 0;
    for (int i = 0; i < n; i++) {
        if(cs[i] != tar[i]){
            cnt++;
        }
        x += cs[i]-'0';
        y += tar[i] -'0';
    }
    int ans = Integer.MAX_VALUE;
    if(x == y){
       ans = cnt;
    }
    if(x == n -y + 1){
        ans = Math.min(ans, n - cnt);
    }
    out.println(ans == Integer.MAX_VALUE?-1:ans);

}