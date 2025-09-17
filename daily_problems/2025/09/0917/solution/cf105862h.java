public static void solve(){
    int T = sc.nextInt();

    while (T > 0){
        T -= 1;

        int n = sc.nextInt();
        long sum = 0, times = 0;
        for (int i = 1; i <= n; ++ i){
            sum += sc.nextInt();
            if (sum > mod) sum -= mod;
            times += n / __gcd(n, i);
        }
        times %= mod;
        long rev = pow(n, mod-2);

        long res = sum * times % mod * rev%mod * rev%mod;
        out.println(res);
    }
}
