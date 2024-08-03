#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, m, totxor;

int main() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<vector<int>> M(n, vector<int>(m, 0));
    for (ll i = 0; i < n; i++)
        cin >> a[i], totxor = totxor ^ a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i], totxor = totxor ^ b[i];
    if (totxor) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (ll d = 32; d >= 0; d--) {
        vector<int> rows, cols;
        for (ll i = 0; i < n; i++)
            if (a[i] & (1 << d))
                rows.push_back(i);
        for (ll i = 0; i < m; i++)
            if (b[i] & (1 << d))
                cols.push_back(i);
        while (!rows.empty() && !cols.empty())
            M[rows.back()][cols.back()] |= 1 << d, rows.pop_back(), cols.pop_back();
        while (!rows.empty())
            M[rows.back()][m - 1] |= 1 << d, rows.pop_back();
        while (!cols.empty())
            M[n - 1][cols.back()] |= 1 << d, cols.pop_back();
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    return 0;
}
