/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, ans = 1;
    cin >> n;
    vector a(n + 1, 0), b = a;
    map<int, int> cnt;
    map<int, set<int>> ss;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
        ss[a[i]].insert(i);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        cnt[b[i]] ++;
        ss[b[i]].insert(i);
    }
    cin >> m;

    for (auto [_, cnt] : cnt) {
        int dub = cnt - ss[_].size();
        for (int i = 1; i <= cnt; i ++) {
            int j = i;
            while (dub && j % 2 == 0) {
                j /= 2;
                dub --;
            }
            ans = (ans * j) % m;
        }
    }
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
