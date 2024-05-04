#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dis = 1e9;
    int x = 0;
    for (int i = 1; i <= n - k; i++) {
        if (a[k + i] - a[i] < dis) {
            dis = a[k + i] - a[i];
            x = (a[k + i] + a[i]) / 2;
        }
    }
    cout << x << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}