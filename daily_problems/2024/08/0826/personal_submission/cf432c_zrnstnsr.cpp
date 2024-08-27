#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

constexpr int maxn = 100000;
bitset<maxn+1> notprime;
vector<int> prime;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), idx(n+1);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ranges::iota(idx, 0);
    ranges::sort(idx, [&](const int &x, const int &y) { return a[x] < a[y]; });
    for (int i = 1; i <= n; ++i) {
        while (idx[i] > i) {
            int u = *(ranges::upper_bound(prime, idx[i] - i + 1) - 1);
            int j = idx[i] - u + 1;
            ans.push_back({j, idx[i]});
            swap(a[idx[i]], a[j]);
            swap(idx[i], idx[a[idx[i]]]);
        }
    }
    println("{}", ans.size());
    for (auto [u, v]: ans) println("{} {}", u, v);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    for (int i = 2; i <= maxn; ++i) if (!notprime[i]) {
        prime.push_back(i);
        for (auto j = 1LL * i * i; j <= maxn; j += i) notprime[j] = true;
    }
    while (T--) {
        solve();
    }
    return 0;
}
