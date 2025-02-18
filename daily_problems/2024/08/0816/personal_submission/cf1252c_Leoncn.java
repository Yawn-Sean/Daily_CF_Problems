public static void solve() {
    int n = sc.ni();
    int q = sc.ni();
    int[] a = sc.na(n);
    int[] b = sc.na(n);
    int[] c = new int[n];
    int[] d = new int[n];
    for (int i = 0; i < n; i++) {
        c[i] = i;
        d[i] = i;
    }
    for (int i = 1; i < n; i++) {
        if((a[i]&1) == (a[i-1]&1)){
            c[i] = c[i-1];
        }
        if((b[i]&1) == (b[i-1]&1)){
            d[i] = d[i-1];
        }
    }
    while (q-->0){
        int f = sc.ni() - 1;
        int t = sc.ni() - 1;
        int h = sc.ni() - 1;
        int k = sc.ni() - 1;
        if(c[f] == c[h] && d[t] == d[k]){
            out.println("YES");
        }else {
            out.println("NO");
        }
    }
}