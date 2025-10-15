#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> p(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    p[n] = 0;
    int ans = 0;
    for (int j = 1; j < n; j++) {
        if (p[j] - p[j+1] > 1) {
            ans++;
        } else {
            j++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}