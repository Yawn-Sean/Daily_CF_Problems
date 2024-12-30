#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    int mx = 0;
    for (int i = 1; i <= k + 1; i++) {
        cout << "? ";
        for (int j = 1; j <= k + 1; j++) {
            if (i == j) continue;
            cout << j << " ";
        }
        cout << endl;
        int x, y;
        cin >> x >> y;
        mx = max(mx, y);
        cnt[y]++;
    }
    cout << "! " << cnt[mx] << endl;
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