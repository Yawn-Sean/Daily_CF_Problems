#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve() {
    int n, k;
    cin >> n >> k;
    if (k * (k-1) < n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    int cnt = n;
    for (int i = 1; i < k; i++) {
        for (int j = i + 1; j <= k; j++) {
            cout << i << " " << j << '\n';
            cnt--;
            if (cnt == 0) return 0;
            cout << j << " " << i << '\n';
            cnt--;
            if (cnt == 0) return 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}