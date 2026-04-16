#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    multiset<int> a[2];
    multiset<PII, greater<PII>> b;
    for (int i = 1; i <= n; i++) {
        int p, s;cin >> p >> s;
        if (s == 0) a[0].insert(p);
        else a[1].insert(p);
    }
    for (int i = 1; i <= n; i++) {
        int p, s;cin >> p >> s;
        b.insert({p, s});
    }
    
    for (auto [p, s] : b) {
        // cout << p << ' ' << s << endl;
        auto idx = a[s].lower_bound((p + 1) / 2);
        if (idx != a[s].end()) {
            a[s].erase(idx);
            continue;
        }
        idx = a[s ^ 1].lower_bound(p);
        if (idx != a[s ^ 1].end()) {
            a[s ^ 1].erase(idx);
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}