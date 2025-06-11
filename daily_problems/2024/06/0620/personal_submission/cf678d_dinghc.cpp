#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int MOD = 1'000'000'007;

vector<vector<int>> matrix_prod(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    int n = m1.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& c = res[i][j];
            for (int k = 0; k < n; k++) {
                c = (c + static_cast<li>(m1[i][k]) * m2[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> fast_matrix_pow(vector<vector<int>>& a, li b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            res = matrix_prod(res, a);
        }
        a = matrix_prod(a, a);
        b >>= 1;
    }
    return res;
}

vector<int> vector_prod(vector<vector<int>>& m, vector<int>& vec) {
    int n = m.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        auto& c = res[i];
        for (int k = 0; k < n; k++) {
            c = (c + static_cast<li>(m[i][k]) * vec[k]) % MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    li n;
    int A, B, x;
    cin >> A >> B >> n >> x;

    vector<vector<int>> a(2, vector<int>(2, 0));
    a[0][0] = A, a[0][1] = B;
    a[1][0] = 0, a[1][1] = 1;
    vector<vector<int>> ap = fast_matrix_pow(a, n);
    vector<int> v {x, 1};
    vector<int> ans = vector_prod(ap, v);

    cout << ans[0] << "\n";
    return 0;
}

