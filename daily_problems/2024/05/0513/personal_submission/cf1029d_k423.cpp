// https://codeforces.com/contest/1029/submission/260748872

/* 我永远喜欢爱莉希雅♪ */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int H = rng() & numeric_limits<int>::max();

// 自定义的哈希函数
struct my_hash {
    int operator()(int x) const {
        return x ^ H;
    }
};

void elysia() {
    int n, k;
    cin >> n >> k;
    vector<unordered_map<int, int, my_hash>> L(11), R(11);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int x, len = 0;
        cin >> x;
        for (int y = x; y; y /= 10) len++;
        int z = (k - x % k) % k;
        if (L[len].contains(z)) ans += L[len][z];
        for (i64 j = 1, y = x; j <= 10; ++j) {
            y = y * 10 % k;
            z = (k - y % k) % k;
            if (R[j].contains(z)) ans += R[j][z];
        }
        R[len][x % k]++;
        for (i64 j = 1, y = x; j <= 10; ++j) {
            y = y * 10 % k;
            L[j][y]++;
        }
    }
    cout << ans << endl;
}
