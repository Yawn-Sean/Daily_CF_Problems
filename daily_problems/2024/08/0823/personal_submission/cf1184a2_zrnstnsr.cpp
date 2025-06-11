#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> vis(n), bits(n);
    int ans = 1;
    for (int i = 0; i < n; ++i) bits[i] = s[i] - '0', ans &= !bits[i];
    for (int i = 1; i < n; ++i) vis[__gcd(n, i)]++;
    for (int i = 1; i < n; ++i) if (vis[i]) {
        int v = 1;
        for (int j = 0; j < i && v; ++j) {
            int k = j;
            do {
                [[assume(bits[k] == 0 || bits[k] == 1)]];
                v ^= bits[k];
                k = (k + i) % n;
            } while (k != j);
        }
        ans += v * vis[i];
    }
    cout << ans << '\n';
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
