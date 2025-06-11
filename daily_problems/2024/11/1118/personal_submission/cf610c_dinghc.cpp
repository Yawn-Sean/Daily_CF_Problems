#include <bits/stdc++.h>

using namespace std;
char s[(1 << 9) + 1];

int main() {
    int k;
    scanf("%d", &k);
    auto dfs = [&] (auto&& dfs, int n) -> vector<vector<int>> {
        if (n == 0) return vector<vector<int>>(1, vector<int>(1, 1));
        vector<vector<int>> rs = dfs(dfs, n - 1);
        int m = rs.size();
        int m2 = m << 1;
        vector<vector<int>> mat(m2, vector<int>(m2, 0));
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < m2; j++) {
                mat[i][j] = rs[i % m][j % m];
                if (i >= m && j >= m) mat[i][j] = -mat[i][j];
            }
        }
        return mat;
    };
    vector<vector<int>> mat = dfs(dfs, k);
    int m2 = mat.size();
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < m2; j++) {
            s[j] = mat[i][j] == 1 ? '+' : '*';
        }
        s[m2] = '\0';
        printf("%s\n", s);
    }
    return 0;
}

