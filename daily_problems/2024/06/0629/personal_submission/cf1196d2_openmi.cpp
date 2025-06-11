void solve() {
    string s;
    int n, k;
    cin >> n >> k >> s;
    int ans = inf;
    // 大数是限制，小数是突破点！
    vc<char> RGB{'R', 'G', 'B'};
    vector<int> score(3, inf);
    auto check = [&](int p) {
        int ret = inf;
        rep (j, 0, 3) {
            int t = 0, z = j;
            rep (i, p, p + k) {
                if (s[i] != RGB[z]) t++; 
                z++;
                z %= 3;
            }
            score[j] = t;
            chmin(ret, t);
        }
        return ret;
    };
    ans = check(0);
    int shift = 0;
    rep (i, 0, n - k + 1) {
        int last = k % 3;
        int ret = 0;
        rep (j, 0, 3) {
            if (s[i] != RGB[(j + shift) % 3]) score[j] --;
            if (s[i + k] != RGB[(j + last + shift) % 3]) score[j] ++;
            chmin(ans, score[j]);
        }
        shift ++;
        shift %= 3;
    }
    cout << ans << nl;
}
