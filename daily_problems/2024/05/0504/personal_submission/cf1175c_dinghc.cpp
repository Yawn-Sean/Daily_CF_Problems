#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 200000;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        pair<int, int> ans{INT_MAX, 0};
        for (int i = 0; i < n - k; i++) {
            ans = min(ans, {a[i + k] - a[i], (a[i + k] + a[i]) / 2});
        }
        cout << ans.second << "\n";
    }
    return 0;
}

