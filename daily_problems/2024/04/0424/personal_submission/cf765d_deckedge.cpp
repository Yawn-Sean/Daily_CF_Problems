#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), i, m = 0; 
    vector<int> f(n + 1), g(n + 1), h(n + 1);
    for (i = 1; i <= n; i++) {
        cin >> f[i];
        if (f[i] == i) {
            h[++m] = i;
            g[h[m]] = m;
        }
    }
    for (i = 1; i <= n; i++) {
        if (!g[i]) {
            g[i] = g[f[i]];
        }
    }
    bool ok = true;
    for (i = 1; i <= m; i++) {
        if (g[h[i]] != i) {
            ok = false;
            break;
        }
    }
    for (i = 1; i <= n; i++) {
        if (h[g[i]] != f[i]) {
            ok = false;
            break;
        }
    }
    if (ok && m) {
        cout << m << '\n';
        for (i = 1; i <= n; i++) {
            cout << g[i] << " \n"[i == n];
        }
        for (i = 1; i <= m; i++) {
            cout << h[i] << " \n"[i == m];
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}

