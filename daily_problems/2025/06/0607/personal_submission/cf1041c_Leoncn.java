public static void solve() {
    int n = sc.ni();
    int m = sc.ni();
    int d = sc.ni();
    int[] g = sc.na(n);
    int[][] s = new int[n][2];
    for (int i = 0; i < n; i++) {
        s[i][0] = g[i];
        s[i][1] = i;
    }
    int[] ans = new int[n];
    Arrays.sort(s, Comparator.comparingInt(a -> a[0]));
    int[] res = new int[n];
    int loc = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if(s[i][0]-s[loc][0]<= d){
            res[i] = t;
            t++;
        }else {
            res[i] = res[loc];
            loc++;
        }
        ans[s[i][1]] = res[i];
    }
    out.println(t);
    for (int i = 0; i < n; i++) {
        out.print(ans[i] + 1 + " ");
    }
}