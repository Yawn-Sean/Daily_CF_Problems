#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s += s;
    vector<int> v1(26, 0), v2(26, 0);
    vector<vector<int>> v(26);
    for (int i = 0; i < n; ++i) {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        for (int x = 1; x < n; ++x) {
            fill(v2.begin(), v2.end(), 0);
            for (int p : v[i]) {
                ++v2[s[p + x] - 'a'];
            }
            int tt = 0;
            for (int j = 0; j < 26; ++j) {
                if (v2[j] == 1) {
                    ++tt;
                }
            }
            v1[i] = max(v1[i], tt);
        }
    }
    int tmp = accumulate(v1.begin(), v1.end(), 0);
    cout << fixed << setprecision(6) << static_cast<double>(tmp) / n;
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
