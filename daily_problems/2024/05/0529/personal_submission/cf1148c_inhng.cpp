#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define PII pair<int, int>

signed main() {
    int n;
    cin >> n;
    vector<int> p(n + 1), idx(n + 1);
    vector<PII> ans;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    
    function<void(int, int)> SWAP = [&](int x, int y) {
        ans.emplace_back(x, y);
        swap(idx[p[x]], idx[p[y]]);
        swap(p[x], p[y]);
    };
    
    for (int i = 1; i <= n; ++i) {
        if (p[i] != i) {
            int j = idx[i];
            if (abs(j - i) >= n / 2) {
                SWAP(i, j);
            } else {
                if (i > n / 2) {
                    SWAP(1, i); SWAP(1, j); SWAP(1, i);
                } else if (n - j >= n / 2) {
                    SWAP(i, n); SWAP(j, n); SWAP(i, n);
                } else {
                    SWAP(i, n); SWAP(1, n); SWAP(1, j); SWAP(1, n); SWAP(i, n);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << " " << y << endl;
    }
    return 0;
}
