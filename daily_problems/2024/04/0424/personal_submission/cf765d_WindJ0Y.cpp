#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    int m = 0;
    vector<int> g(n + 1);
    vector<int> h(n + 1);

    for (int i = 1; i <= n; i++) {
        if (f[f[i]] != f[i]) {
            cout << -1 << "\n";
            return;
        }
        if (f[i] == i) {
            m ++;
            h[m] = i;
            g[i] = m;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!g[i]) {
            g[i] = g[f[i]];
        }
    }

    cout << m << "\n";
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " \n"[i == n];
    }
    for (int i = 1; i <= m; i++) {
        cout << h[i] << " \n"[i == m];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}