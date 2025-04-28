#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, tmp = 1;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n-1; ++i) {
        tmp += s[i] != s[i+1];
    }
    cout << min(n, tmp+2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}