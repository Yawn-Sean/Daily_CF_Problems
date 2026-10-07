#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

template <typename T>
struct Trie {
    constexpr static int B = numeric_limits<T>::digits;
    vector<array<T, 2>> tree;
    vector<i64> cnt;
    int tot = 0;
    Trie() = default;
    Trie(int n) : tree(B * n), cnt(B * n) {}
    void insert(const T& x) {
        int cur = 0;
        for (int i = B - 1; i >= 0; i--) {
            bool bit = (x >> i) & 1;
            if (!tree[cur][bit]) {
                tree[cur][bit] = ++tot;
            }
            cnt[cur]++;
            cur = tree[cur][bit];
        }
        cnt[cur]++;
    }
    T query(const T& x, const T& y) {
        int cur = 0;
        T res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int l = x >> i & 1, r = y >> i & 1;
            if (r) {
                if (tree[cur][l]) {
                    res += cnt[tree[cur][l]];
                }
                if (tree[cur][l ^ 1]) {
                    cur = tree[cur][l ^ 1];
                } else {
                    break;
                }
            } else {
                if (tree[cur][l]) {
                    cur = tree[cur][l];
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

constexpr int md = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, x;
    cin >> n >> x;
    Trie<i64> tr(n + 1);
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tr.insert(a[i]);
    }

    sort(a.begin() + 1, a.end());

    i64 ans = 1;
    if (x == 0) {
        for (int i = 1; i <= n; i++) {
            ans = ans * 2 % md;
        }
        cout << ans - 1 << "\n";
        return 0;
    }

    i64 k = __lg(x) + 1;
    vector<int> K(n + 1);
    map<i64, i64> mp;
    for (int i = 1; i <= n; i++) {
        K[i] = a[i] / (1LL << k);
        mp[K[i]]++;
    }

    map<i64, i64> res;
    for (int i = 1; i <= n; i++) {
        i64 cnt = tr.query(a[i], x);
        res[K[i]] += mp[K[i]] - cnt;
    }

    for (const auto& [l, r] : mp) {
        ans = ans * (res[l] / 2 + r + 1) % md;
    }

    cout << ans - 1;
    return 0;
}