#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <typename T>
bool chmin(T &a, const T &b) {
    return b < a ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    return b > a ? a = b, true : false;
}

constexpr int inf = 1E9;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, i64> cnt;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    int mex = 0;
    while (cnt[mex]) {
        mex++;
    }

    std::vector<i64> f(mex + 1, inf);
    f[mex] = 0;
    for (int i = mex; i; i--) {
        for (int j = 0; j < i; j++) {
            chmin(f[j], f[i] + i * (cnt[j] - 1) + j);
        }
    }
    std::cout << f[0] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
