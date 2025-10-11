#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> res[i];
    int cnt = min(l - 1, n - r);
    sort(res.begin() + 1, res.end() - cnt, greater<int>());
    ll ans = 0;
    for (int i = 1; i <= r - l + 1; i++) {
        ans += res[i];
    }
    cout << ans << endl;
    return 0;
}