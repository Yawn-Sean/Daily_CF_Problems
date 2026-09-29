#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

template <class T>
struct BIT {
    int n;
    vector<T> w;
    BIT(int n) {
        w.resize(n + 1);
        this->n = n;
    }

    void add(int x, T v) {
        while (x <= n) {
            w[x] += v;
            x += x & -x;
        }
    }

    T ask(int x) {
        T ans = 0;
        while (x) {
            ans += w[x];
            x -= x & -x;
        }
        return ans;
    }
};

constexpr int N = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> mn(N + 1);
    iota(mn.begin(), mn.end(), 0);
    for (int i = 2; i <= N; i++) {
        if (mn[i] != i) {
            continue;
        }
        for (int j = i; j <= N; j += i) {
            mn[j] = i;
        }
    }

    auto get_fac = [&](int x) -> vector<int> {
        vector<int> ans(1, 1);
        while (x > 1) {
            int v = mn[x], cnt = 0, len = ans.size();
            while (x % v == 0) {
                x /= v, cnt++;
            }
            for (int i = 0; i < len * cnt; i++) {
                ans.push_back(ans[i] * v);
            }
        }
        return ans;
    };

    auto p = a;
    ranges::sort(p);
    p.erase(unique(p.begin() + 1, p.end()), p.end());

    auto get = [&](int x) -> int { return lower_bound(p.begin() + 1, p.end(), x) - p.begin(); };

    vector<vector<i64>> g(N + 1);
    for (int i = 1; i <= n; i++) {
        for (const auto& v : get_fac(b[i])) {
            g[v].push_back(get(a[i]));
        }
    }

    BIT<Mint> bt(n);
    vector<Mint> r(N + 1);
    for (int i = 1; i <= N; i++) {
        for (const auto& v : g[i]) {
            Mint res = bt.ask(v - 1) + 1;
            r[i] += res;
            bt.add(v, res);
        }
        bt.w.assign(n + 1, 0);
    }

    auto ans = r;
    for (int i = N; i >= 1; i--) {
        for (int j = 2; j * i <= N; j++) {
            ans[i] -= ans[j * i];
        }
    }

    Mint res = 0;
    for (int i = 1; i <= N; i++) {
        res += ans[i] * i;
    }

    cout << res;
    return 0;
}