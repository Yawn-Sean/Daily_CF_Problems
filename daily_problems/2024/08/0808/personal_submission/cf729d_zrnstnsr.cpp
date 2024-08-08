#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<pair<int,int>> sp;
    int cnt = 0, start = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') { if (!cnt++) start = i; }
        else if (cnt) sp.push_back({cnt, start}), cnt = 0;
    if (cnt) sp.push_back({cnt, start});
    // sort(sp.begin(), sp.end());
    int m = 0;
    for (auto [t, l]: sp) m += t / b;
    m -= a - 1;
    vector<int> ans;
    for (auto [t, l]: sp) {
        while (t >= b) {
            ans.push_back(l + b);
            t -= b; l += b;
            if (!--m) goto end;
        }
    }
    end: cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i == ans.size() - 1];
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
