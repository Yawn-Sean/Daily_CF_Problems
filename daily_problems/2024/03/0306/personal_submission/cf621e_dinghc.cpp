#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int const mod = 1000000007;

vector<vector<int>> matrix_mult(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    int n = m1.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& c = res[i][j];
            for (int k = 0; k < n; k++) {
                c = (c + static_cast<int64>(m1[i][k]) * m2[k][j]) % mod;
            }
        }
    }
    return res;
}

vector<vector<int>> fast_matrix_pow(vector<vector<int>>& a, int b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            res = matrix_mult(res, a);
        }
        a = matrix_mult(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    int n, b, k, x;
    cin >> n >> b >> k >> x;

    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    
    vector<vector<int>> matrix(x, vector<int>(x, 0));
    for (int i = 0; i < x; i++) {
        for (auto& aj : a) {
            matrix[i][(10 * i + aj) % x]++;
        }
    }
    
    vector<vector<int>> ans = fast_matrix_pow(matrix, b);
    cout << ans[0][k] << endl;
    return 0;
}

