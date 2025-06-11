#define int i128

void solve() {
    int n;
    cin >> n;
    vec<int> ans;

    auto check = [&](int x) -> bool {
        int r = 1;
        while (x % 2 == 0) {
            x /= 2;
            r *= 2;
        }
        return x * (x - 1) / 2 + x * (r - 1) == n;
    };

    // i * i / 2 + (r - (3 / 2)) * i - n = 0;
    for (int r = 1; r <= n; r *= 2) {
        int L = 0, R = 1e18;
        while (L + 1 < R) {
            int m = (L + R) / 2;
            if (m * m + (2 * r - 3) * m <= 2 * n) {
                L = m;
            } else {
                R = m;
            }
        }

        if (L * L + (2 * r - 3) * L == 2 * n && check(L * r)) {
            ans.push_back(L * r);
        }
    }

    if (ans.empty()) ans.push_back(-1);
    ranges::sort(ans);
    for (int i : ans) {
        cout << i << '\n';
    }
}
