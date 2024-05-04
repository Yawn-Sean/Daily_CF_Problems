#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -1, mn = 2e9;
    for (int i = 0; i + k < n; i++) {
        int d = (a[i + k] - a[i] + 1) / 2;
        if (d < mn) ans = a[i] + d, mn = d;
    }
    cout << ans << '\n';

    return 0;
}
