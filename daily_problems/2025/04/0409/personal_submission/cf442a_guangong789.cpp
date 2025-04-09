#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 * 32 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;

map<char, int> mp = {{'R', 1}, {'G', 2}, {'B', 3}, {'Y', 4}, {'W', 5}};

int popcount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string s;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        st.insert(mp[s[0]] * 10 + (s[1] - '0'));
    }
    int len = st.size(), ans = inf;
    for (int color = 0; color < 32; ++color) {
        for (int num = 0; num < 32; ++num) {
            set<int> find;
            for (int c : st) {
                int cur = 0;
                if ((color >> (c / 10 - 1)) & 1) {
                    cur += 10 * (c/ 10);
                }
                if ((num >> (c % 10 - 1)) & 1) {
                    cur += c % 10;
                }
                find.insert(cur);
            }
            if (find.size() == len) {
                ans = min(ans, popcount(color) + popcount(num));
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
