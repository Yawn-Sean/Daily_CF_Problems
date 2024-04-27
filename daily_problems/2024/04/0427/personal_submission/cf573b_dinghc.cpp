#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 100001;
int h[MXN];
int l[MXN];
int r[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 0, mn = 0; i < n + 1; i++) {
        mn = min(mn, h[i]);
        l[i] = mn;
        mn += 1;
    }

    for (int i = n + 1, mn = 0; i > 0; i--) {
        mn = min(mn, h[i]);
        r[i] = mn;
        mn += 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, min(l[i], r[i]));
    }

    cout << ans << "\n";

    return 0;
}

