#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi; pi--;
    }
    
    int c1 = -1, c2 = -1;
    int odd = 0;
    vector<vector<int>> cycles;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> st{i};
        vis[i] = true;
        int x = p[i];
        while (x != i) {
            vis[x] = true;
            st.push_back(x);
            x = p[x];
        }
        cycles.push_back(st);
        if (st.size() % 2 == 1) odd++;
        if (st.size() == 1) {
            c1 = cycles.size() - 1;
        } else if (st.size() == 2) {
            c2 = cycles.size() - 1;
        }
    }

    if (c1 != -1) {
        cout << "YES\n";
        int center = cycles[c1][0];
        for (int i = 0; i < n; i++) {
            if (i == center) continue;
            cout << center + 1 << " " << i + 1 << "\n";
        }
    } else if (c2 != -1) {
        if (odd) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << cycles[c2][0] + 1 << " " << cycles[c2][1] + 1 << "\n";
            for (int j = 0; j < cycles.size(); j++) {
                if (j == c2) continue;
                auto& cc = cycles[j];
                for (int i = 0; i < cc.size(); i++) {
                    cout << cycles[c2][i % 2] + 1 << " " << cc[i] + 1 << "\n";
                }
            }
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
