#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
static constexpr int MOD = 1'000'000'007;

inline int norm(i64 x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return int(x);
}

struct Bounds {
    vector<int> left, right;
};

static Bounds build_bounds(const vector<int>& a) {
    int n = (int)a.size();
    Bounds b{vector<int>(n), vector<int>(n)};
    vector<int> stk;

    // prev greater (strict), sentinel -1
    stk.clear(); stk.push_back(-1);
    for (int i = 0; i < n; ++i) {
        while (stk.back() != -1 && a[stk.back()] <= a[i]) stk.pop_back();
        b.left[i] = stk.back();
        stk.push_back(i);
    }

    // next greater (strict), sentinel n
    stk.clear(); stk.push_back(n);
    for (int i = n - 1; i >= 0; --i) {
        while (stk.back() != n && a[stk.back()] <= a[i]) stk.pop_back();
        b.right[i] = stk.back();
        stk.push_back(i);
    }
    return b;
}

static pair<vector<int>, vector<int>> build_prefix(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> acc1(n + 1, 0), acc2(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        acc1[i + 1] = norm((i64)acc1[i] + a[i]);
        acc2[i + 1] = norm((i64)acc2[i] + (i64)a[i] * i);
    }
    return {acc1, acc2};
}

static int solve_one(const vector<int>& a) {
    int n = (int)a.size();

    auto [acc1, acc2] = build_prefix(a);
    Bounds bd = build_bounds(a);

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int L = bd.left[i], R = bd.right[i];

        // term1: a[i] * (i-L) * (R-i)
        ans += (i64)a[i] * (i - L) % MOD * (R - i) % MOD;

        // term2: ((acc2[i]-acc2[L+1]) - (acc1[i]-acc1[L+1])*L) * (R-i)
        int s1 = norm((i64)acc2[i] - acc2[L + 1]);
        int s0 = norm((i64)acc1[i] - acc1[L + 1]);
        ans += (i64)norm((i64)s1 - (i64)s0 * L) * (R - i) % MOD;

        // term3: ((acc1[R]-acc1[i+1])*R - (acc2[R]-acc2[i+1])) * (i-L)
        int t0 = norm((i64)acc1[R] - acc1[i + 1]);
        int t1 = norm((i64)acc2[R] - acc2[i + 1]);
        ans += (i64)norm((i64)t0 * R - t1) * (i - L) % MOD;

        ans %= MOD;
    }
    return norm(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    cout << solve_one(a);
    return 0;
}
