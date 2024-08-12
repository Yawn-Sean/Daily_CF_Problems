#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    m--;
    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
        if ((m >> (n - 1 - i)) & 1)
            ans[r--] = i;
        else
            ans[l++] = i;
    }
    ans[l] = n;
    for (int i : ans) cout << i << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}