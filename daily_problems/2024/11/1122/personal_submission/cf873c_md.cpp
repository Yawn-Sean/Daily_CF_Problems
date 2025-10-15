#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> mat(m, std::vector<int>(n));
    std::vector<int> minpos(m, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> mat[j][i];
            if (mat[j][i] == 1 && minpos[j] == -1) {
                minpos[j] = i;
            }
        }
    }

    int ret = 0;
    int totCost = 0;
    for (int i = 0; i < m; ++i) {
        int mincost = 0;
        int maxval = 0;
        
        int left = 0;
        int right = 0;
        int onecnt = 0;
        int cost = 0;

        auto updateMaxVal = [&](int left) {
            if (mat[i][left] == 1) {
                if (maxval < std::min(k, onecnt) || (maxval == std::min(k, onecnt) && mincost > cost)) {
                    maxval = std::min(k, onecnt);
                    mincost = cost;
                }
            }
        };

        for (right = 0; right < k; ++right) {
            onecnt += mat[i][right];
        }

        for (; right < n; ++right) {
            updateMaxVal(left);

            onecnt += mat[i][right];
            onecnt -= mat[i][left];
            cost += mat[i][left];
            ++left;
        }

        for (; left < n; ++left) {
            updateMaxVal(left);

            onecnt -= mat[i][left];
            cost += mat[i][left];            
        }

        ret += maxval;
        totCost += mincost;
    }

    std::cout << ret << ' ' << totCost << '\n';

    return 0;
}