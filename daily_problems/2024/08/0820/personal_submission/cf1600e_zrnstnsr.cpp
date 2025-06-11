#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int pre = 1, suf = 1;
    for (int i = 1; i < n; ++i) if (a[i] > a[i-1]) ++pre; else break;
    for (int i = n - 2; i >= 0; --i) if (a[i] > a[i+1]) ++suf; else break;
    cout << (pre % 2 == 0 && suf % 2 == 0 ? "Bob\n" : "Alice\n");
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
