#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    vector<int> mn(n + 1, INT_MAX);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cnt[a]++;
        mn[a] = min(mn[a], (b + n - a) % n);
    }
    for (int s = 1; s <= n; s++) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) continue;
            ans = max(ans, (i + n - s) % n + (cnt[i] - 1) * n + mn[i]);
        }
        cout << ans << " ";
    }
    return 0;
}

