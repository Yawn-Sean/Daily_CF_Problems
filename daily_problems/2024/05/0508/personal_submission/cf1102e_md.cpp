// 0508
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 998244353;

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % modulus;
        }   
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> a(n);
    map<int, vector<int>> same_vals;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        same_vals[a[i]].push_back(i);
    }

    vector<pair<int, int>> p;
    for (auto&[_, vec] : same_vals) {
        if (size(vec) >= 2) {
            p.emplace_back(vec[0], vec.back());
        }
    }

    sort(begin(p), end(p));

    i64 seg_cnt = 0;
    int p_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (p_idx < ssize(p) && i == p[p_idx].first) {
            int right = p[p_idx].second;
            ++seg_cnt;
            ++p_idx;
            while (p_idx < ssize(p) && p[p_idx].first <= right) {
                right = max(right, p[p_idx].second);
                ++p_idx;
            }
            i = right;
        } else {
            ++seg_cnt;
        }
    }

    auto ans = modpow<i64>(2ll, seg_cnt - 1, MOD);
    cout << ans << endl;

    return 0;
}