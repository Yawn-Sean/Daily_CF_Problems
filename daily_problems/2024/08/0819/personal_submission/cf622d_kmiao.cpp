#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi res;
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i += 2)
            res.pb(i);
        for (int i = n - 2; i >= 1; i -= 2)
            res.pb(i);
        for (int i = 2; i <= n - 1; i += 2)
            res.pb(i);
        for (int i = n - 1; i >= 2; i -= 2)
            res.pb(i);
    } else {
        for (int i = 1; i <= n - 1; i += 2)
            res.pb(i);
        for (int i = n - 1; i >= 1; i -= 2)
            res.pb(i);
        for (int i = 2; i <= n; i += 2)
            res.pb(i);
        for (int i = n - 2; i >= 2; i -= 2)
            res.pb(i);
    }
    res.pb(n);
    for (int i = 0; i < 2 * n; i++)
        cout << res[i] << " \n"[i == 2 * n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
