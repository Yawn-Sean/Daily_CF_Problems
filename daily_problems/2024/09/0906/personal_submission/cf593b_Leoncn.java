public static void solve() {
    int n = sc.ni();
    long x1 = sc.ni();
    long x2 = sc.ni();
    long[][] g = new long[n][2];
    for (int i = 0; i < n; i++) {
        long a = sc.ni();
        long b = sc.ni();
        g[i][0] = a * x1 + b;
        g[i][1] = a * x2 + b;
    }
    Arrays.sort(g,(a,b)->{
        if(Long.compare(a[0],b[0]) == 0 ){
            return Long.compare(a[1],b[1]);
        }
        return Long.compare(a[0],b[0]);
    });
    long max = Long.MIN_VALUE;
    for (int i = 0; i < n; i++) {
        if(g[i][1]<max){
            out.println("YES");
            return;
        }
        max = Math.max(g[i][1], max);
    }
    out.println("NO");
}
