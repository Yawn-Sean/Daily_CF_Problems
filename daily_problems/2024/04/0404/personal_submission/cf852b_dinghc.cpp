#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int const mod = 1000000007;

vector<vector<int>> matrix_prod(vector<vector<int>>& m1, vector<vector<int>>& m2) {
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
            c = (c + static_cast<int64>(m[i][k]) * vec[k]) % mod;
        }
    }
    return res;
}

constexpr int MXN = 1000001;
int costs[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, M;
    cin >> N >> L >> M;

    vector<int> dp(M, 0);
    for (int i = 0; i < N; i++) {
        int cst;
        cin >> cst;
        dp[cst % M]++;
    }

    vector<int> num(M, 0);
    for (int i = 0; i < N; i++) {
        int cst;
        cin >> cst;
        num[cst % M]++;
        costs[i] = cst;
    }

    for (int i = 0; i < N; i++) {
        int cst;
        cin >> cst;
        costs[i] += cst;
    }

    vector<vector<int>> a(M, vector<int>(M, 0));
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < M; i++) {
            a[j][i] = num[(j + M - i) % M];
        }
    }

    vector<vector<int>> ap = fast_matrix_pow(a, L - 2);
    dp = vector_prod(ap, dp);

    int64 ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans = (ans + dp[(M - costs[i] % M) % M]) % mod;
    }

    cout << ans << "\n";

    return 0;
}

