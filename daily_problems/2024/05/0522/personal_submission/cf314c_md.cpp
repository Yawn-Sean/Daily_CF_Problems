// 0522
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 1;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) { init(n); }
    void init(int n) { this->n = n; a.assign(n, T()); }

    // set num[x] = v
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v; a[i - 1] %= MOD;
        }
    }

    // sum of [0, x)    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1]; ans %= MOD;
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<i64> nums(n);
    copy_n(istream_iterator<i64>(cin), n, begin(nums));

    Fenwick<i64> fen(MAXN);
    array<i64, MAXN> dp{0};

    fen.add(0, 1);
    for (auto num : nums) {
        i64 v = (num * fen.sum(num + 1) - dp[num] + MOD) % MOD;
        dp[num] += v;
        fen.add(num, v);
    }

    cout << accumulate(begin(dp), end(dp), 0ll, [](auto x, auto y) { return (x + y) % MOD; }) << endl;    
    return 0;
}