void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);
    srt(a);
    vi cnt(5000);
    vl ccnt(5001);
    int mx = 0;
    // 对差值计数
    rep (i, 1, n) rep (j, 0, i) {
        cnt[a[i] - a[j]]++; 
        chmax(mx, a[i] - a[j]);
    }
    // 无差别计数前两轮差值
    rep (i, 2, mx) rb (j, 1, i) ccnt[i] += cnt[j] * cnt[i - j];
 
    // 求前缀和，方便后面计算答案
    rb (i, 1, mx) ccnt[i] += ccnt[i - 1];
 
    ll ans = 0, b = n * (n - 1) / 2;
    b = b * b * b;
 
    // 枚举最大差值
    rep (i, 1, n) rep (j, 0, i) {
        ans += ccnt[a[i] - a[j] - 1];
    }
    
    cout << setprecision(10) << 1.0 * ans / b;
}
