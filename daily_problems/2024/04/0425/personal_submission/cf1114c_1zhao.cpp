void solve() {
    long long n, b;
    cin >> n >> b;

    unordered_map<long long, long long> um;
    for(int i=2; i<=b/i; i++) {
        while(b % i == 0) {
            um[i] ++;
            b /= i;
        }
    }
    if(b != 1) um[b] ++;

    long long res = 2e18;

    for(auto&[k,v]: um) {
        long long cnt = 0;
        long long t = k;
        while(t <= n) {
            cnt += n / t;
            if(t <= n / k) t *= k;
            else break;
        }
        res = min(res, cnt / v);
    }

    cout << res << endl;
}
