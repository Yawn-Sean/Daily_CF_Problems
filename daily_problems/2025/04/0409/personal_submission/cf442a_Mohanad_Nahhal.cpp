/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector a(n + 1, string());
    for (int i = 1; i <= n; i ++) cin >> a[i];

    vector b = {'R', 'G', 'B', 'Y', 'W', '1', '2', '3', '4', '5'};
    map<char, int> did;
    int ans = 1000, siz = 0;
    function<void(int)> f = [&] (int x) {
        if (x == b.size()) {
            map<char, set<string>> mp;
            set<string> zero;
            for (int i = 1; i <= n; i ++) {
                char aa = a[i][0], bb = a[i][1];
                int aaa = did[aa], bbb = did[bb];
                if (aaa + bbb == 2) continue;
                else if (aaa + bbb == 0) zero.insert(a[i]);
                else if (aaa) mp[aa].insert(a[i]);
                else mp[bb].insert(a[i]);
            }

            if (zero.size() > 1) return;
            for (auto [_, s] : mp) {
                if (s.size() > 1) return;
            }
            ans = min(ans, siz);
            return;
        }
        did[b[x]] ++;
        siz ++;
        f(x + 1);
        did[b[x]] --;
        siz --;
        f(x + 1);
    };
    f(0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
