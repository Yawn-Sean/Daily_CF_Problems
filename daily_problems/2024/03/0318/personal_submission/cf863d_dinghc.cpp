#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    int n, q, m;
    cin >> n >> q >> m;
    
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<array<int, 3>> queries(q);
    for (auto& [t, l, r] : queries) {
        cin >> t >> l >> r;
        l--; r--;
    }
    vector<int> b(m);
    for (auto& x : b) {
        cin >> x;
        x--;
    }

    for (auto pos : b) {
        for (int i = q - 1; i >= 0; i--) {
            auto& [t, l, r] = queries[i];
            if (l > pos || r < pos) continue;
            int k = r - l + 1;
            if (t == 1) {
                pos = (pos - l - 1 + k) % k + l;
            } else {
                pos = k - 1 - (pos - l) + l;
            }
        }
        cout << a[pos] << " ";
    }

    cout << "\n";

    return 0;
}
