#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0), near(n, n), dis(n, 0), sufmx(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++;
        near[a] = min(near[a], (n + b - a) % n);
    }
    for (int i = n-1; i >= 0; i--) {
        dis[i] = (cnt[i] - 1) * n + near[i] % n + i;
        sufmx[i] = max(sufmx[i+1], dis[i]);
    }
    int premx = 0;
    for (int i = 0; i < n; i++) {
        cout << max(premx, sufmx[i]) - i << ' ';
        premx = max(premx, dis[i] + n);
    }
    cout << '\n';

    return 0;
}
