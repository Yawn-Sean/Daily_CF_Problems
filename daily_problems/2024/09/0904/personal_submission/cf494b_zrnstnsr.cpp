#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<ll> d(n + 1), sum(n + 1), sum2(n + 1);
    vector<int> matches;
    
    auto kmp = [&]() { 
        vector<int> next(m);
        for (int i = 1; i < m; ++i) {
            int j = next[i-1];
            while (j > 0 && t[i] != t[j]) j = next[j - 1];
            if (t[i] == t[j]) ++j;
            next[i] = j;
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && s[i] != t[j]) j = j ? next[j-1] : -1;
            if (++j == m) matches.push_back(i), j = next[j-1];
        }
    };

    kmp();
    auto it = matches.begin();
    for (int i = 0; i < n; ++i) {
        d[i+1] = d[i];
        if (it != matches.end() && *it == i) {
            d[i+1] = (sum2[i-m+1] + i - m + 2) % mod;
            ++it;
        }
        sum[i+1] = (sum[i] + d[i+1]) % mod;
        sum2[i+1] = (sum2[i] + sum[i+1]) % mod;
    }
    // for (int i = 0; i <= n; ++i) print("{} ", d[i]);
    println("{}", sum[n]);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
