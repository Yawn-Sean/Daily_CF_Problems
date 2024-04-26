#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 300000;
int ls[MXN];
int rs[MXN];
int pre_mn[MXN+1];
int pre_mx[MXN+1];
int suf_mn[MXN+1];
int suf_mx[MXN+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ls[i] >> rs[i];
    }

    pre_mx[0] = 0;
    pre_mn[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        pre_mx[i] = max(pre_mx[i - 1], ls[i - 1]);
        pre_mn[i] = min(pre_mn[i - 1], rs[i - 1]);
    }

    suf_mx[n] = 0;
    suf_mn[n] = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        suf_mx[i] = max(suf_mx[i + 1], ls[i]);
        suf_mn[i] = min(suf_mn[i + 1], rs[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = max(pre_mx[i], suf_mx[i+1]);
        int mn = min(pre_mn[i], suf_mn[i+1]);
        ans = max(ans, mn - mx);
    }

    cout << ans << "\n";

    return 0;
}

