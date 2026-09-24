#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

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

constexpr int N = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int Knum = 317;
    vector<int> K(n + 1);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        K[i] = (i - 1) / Knum + 1;
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<array<int, 4>> query;
    query.reserve(q);
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        query.push_back({l, r, k, i - 1});
    }

    sort(query.begin(), query.end(), [&](auto& x, auto& y) {
        if (K[x[0]] != K[y[0]]) {
            return x[0] < y[0];
        }
        if (K[x[0]] & 1) {
            return x[1] < y[1];
        }
        return x[1] > y[1];
    });

    vector<i64> ans(q);
    vector<int> cnt1(N + 1), cnt2(N + 1);
    BIT<int> bt1(N + 1), bt2(N + 1);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        auto [cl, cr, k, id] = query[i];
        while (l > cl) {
            --l;
            if (a[l] <= N) {
                cnt1[a[l]]++, bt1.add(a[l], 1);
            }
            if (b[l] <= N) {
                cnt2[b[l]]++, bt2.add(b[l], 1);
            }
        }
        while (r < cr) {
            ++r;
            if (a[r] <= N) {
                cnt1[a[r]]++, bt1.add(a[r], 1);
            }
            if (b[r] <= N) {
                cnt2[b[r]]++, bt2.add(b[r], 1);
            }
        }
        while (l < cl) {
            if (a[l] <= N) {
                cnt1[a[l]]--, bt1.add(a[l], -1);
            }
            if (b[l] <= N) {
                cnt2[b[l]]--, bt2.add(b[l], -1);
            }
            l++;
        }
        while (r > cr) {
            if (a[r] <= N) {
                cnt1[a[r]]--, bt1.add(a[r], -1);
            }
            if (b[r] <= N) {
                cnt2[b[r]]--, bt2.add(b[r], -1);
            }
            r--;
        }

        i64 res = 0, w1 = 0, w2 = 0;
        for (int i = 1; i * i <= k; i++) {
            res += 1LL * cnt1[i] * bt2.ask(k / i);
            res += 1LL * cnt2[i] * bt1.ask(k / i);
            w1 += cnt1[i], w2 += cnt2[i];
        }

        ans[id] = res - w1 * w2;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}