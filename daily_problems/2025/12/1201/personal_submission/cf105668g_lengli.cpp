#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> outs;

    const int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        vector<long long> tmp;
        tmp.reserve(n * m);

        long long res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res ^= (grid[i][j] & 1LL);
                long long x = (grid[i][j] * 1LL * n + i) * m + j;
                tmp.push_back(x);
            }
        }

        sort(tmp.begin(), tmp.end());

        vector<vector<long long>> to_fill(n, vector<long long>(m, -1));

        for (long long x : tmp) {
            long long msk = x % (n * 1LL * m);
            long long i = msk / m;
            long long j = msk % m;

            long long val = -1;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    val = max(val, to_fill[ni][nj]);
                }
            }

            to_fill[i][j] = val + 1;
            res ^= ((val + 1) & 1LL);
        }

        outs.push_back(res ? "Yes" : "No");
    }

    for (auto &s : outs) cout << s << "\n";

    return 0;
}
