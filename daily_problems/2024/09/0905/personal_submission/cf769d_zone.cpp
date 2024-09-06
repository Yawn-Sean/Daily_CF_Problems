void solve() {
    int n, k;
    std::cin >> n >> k;


    std::vector<int> a(n);
    for(auto &x: a) std::cin >> x;

    std::vector<int> cnt(1 << 14);
    for (auto x: a) cnt[x] ++;
    
    i64 ans = 0;

    if (k == 0) {
        for (auto v: cnt) {
            ans += 1LL * (v - 1) * v;
        }
    } else {
        std::vector<int> vals;
        for (int i = 0; i < 1 << 14; i ++ ) {
            int c = 0;
            for (int j = 0; j < 14; j ++ ) {
                c += (i >> j) & 1;
            }
            if (c == k) vals.push_back(i);
        }

        for (int i = 0; i < 1 << 14; i ++ ) {
            for (auto j: vals) {
                ans += 1LL * cnt[i] * cnt[i ^ j];
            }
        }
    }
    std::cout << ans / 2 << std::endl;
}
