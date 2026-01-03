#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> deg(n + 1, 0);
    vector<string> outs;

    for (int i = 0; i < m + k; i++) {
        int u, v;
        cin >> u >> v;
        deg[u] ^= 1;
        deg[v] ^= 1;
        if (u > 1 && v > 1) {
            outs.push_back("1 " + to_string(u) + " " + to_string(v));
        }
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (deg[i]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << outs.size() << '\n';
        for (auto &s : outs) {
            cout << s << '\n';
        }
    }

    return 0;
}
