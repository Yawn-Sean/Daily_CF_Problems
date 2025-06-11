public static void solve() {
    int n = sc.ni();
    int k = sc.ni();
    long ans = 1;
    if(k >= 2){
        ans += comb(n,2);
    }
    if(k>=3){
        ans += comb(n,3) * 2;
    }
    if(k>=4){
        ans += comb(n,4)* 9;
    }
    out.println(ans);
}

private static long comb(int n, int k){
    long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans*( n-i) /(i+1);
    }
    return ans;
}