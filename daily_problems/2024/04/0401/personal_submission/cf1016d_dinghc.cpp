#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int a_xor = 0;
    for (auto& x : a) {
        cin >> x;
        a_xor ^= x;
    }
    
    vector<int> b(m);
    int b_xor = 0;
    for (auto& x : b) {
        cin >> x;
        b_xor ^= x;
    }
    
    if (a_xor != b_xor) {
        cout << "NO\n";
    } else {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        ans[0][0] = a[0];
        for (int i = 1; i < m; i++) {
            ans[0][i] = b[i];
            ans[0][0] ^= b[i];
        }
        for (int i = 1; i < n; i++) {
            ans[i][0] = a[i];
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}

