#include <bits/stdc++.h>
using i64 = long long;
const int N = 3010, M = 3010;
int n, m, st[N];
i64 sum[N], ans = 1e18;
std::vector<int> voters[N];
std::vector<int> res;


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    res.reserve(n);
    for (int i = 0, p, c; i < n; i ++) {
        std::cin >> p >> c, voters[p].push_back(c);
        sum[p] ++;
    }
    for (int i = 1; i <= m; i ++)    std::sort(voters[i].begin(), voters[i].end());
    for (int i = 1; i <= (n - 1) / 2 + 1; i ++) {
        i64 tot = 0;
        int cur = sum[1];
        for (int j = 2; j <= m; j ++) {
            int& p = st[j] = 0;
            for(int ed = st[j] + sum[j] - i + 1; p < ed; p ++)
                tot += voters[j][p], cur ++;
        }
        if (cur < i) {
            res.clear();
            for (int j = 2; j <= m; j ++) {
                int& p = st[j];
                for(int ed = voters[j].size(); p < ed; p ++)
                    res.push_back(voters[j][p]);
            }
            sort(res.begin(), res.end());
            for(int j = 0, ed = i - cur; j < ed; j ++)
                tot += res[j];
        }
        ans = std::min(ans, tot);
    }
    std::cout << ans;
    return 0;
}
