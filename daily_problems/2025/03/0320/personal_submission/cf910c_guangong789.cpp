#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> frt(11, 0);
    map<int, int> cnt;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        frt[s[0] - 'a'] = 1;
        int l = s.length();
        for (int j = 0; j < l; ++j) {
            cnt[s[j] - 'a'] += pow(10, l-j-1);
        }
    }
    vector<pair<int, int>> vp;
    for (auto& [key, value] : cnt) {
        vp.emplace_back(key, value);
    }
    sort(vp.begin(), vp.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    bool use = false;
    int ans = 0, tmp = 1;
    for (auto& p : vp) {
        if (!frt[p.first] && !use) {
            ans += 0;
            use = true;
        } else {
            ans += p.second * tmp;
            tmp++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
