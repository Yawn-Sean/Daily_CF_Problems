#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int m; cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    int ans[128] = {0};
    for (char c = 'a'; c <= 'z'; ++c) {
        bool suc = true;
        int p = -1;
        for (int i = 0; i < n && suc; ++i)
            if (s[i] <= c) p = i;
            else if (i - p >= m) suc = false;
        if (suc) {
            p = -1;
            int pp = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] < c) ++ans[s[p=i]];
                else if (s[i] == c) pp = i;
                if (i - p == m) ++ans[c], p = pp;
            }
            for (char c = 'a'; c <= 'z'; ++c) cout << string(ans[c], c);
            break;
        }
    }
    cout << endl;
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
