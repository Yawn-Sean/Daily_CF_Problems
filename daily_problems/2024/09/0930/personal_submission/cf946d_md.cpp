// 0930
// https://en.oi-wiki.org/dp/knapsack/#_7
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, maxk;
    std::cin>> n >> m >> maxk;

    int tot = 0;

	std::vector<int> dp(maxk + 1);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        std::vector<int> ones;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                ones.push_back(j);
            }
        }

        if (size(ones) > 0) {
            const int fullcost = ones.back() - ones[0] + 1;
            tot += fullcost;
            
            const int onesLen = ssize(ones);
            std::vector<int> improvements(onesLen + 1);
            improvements[onesLen] = fullcost;

            for (int j = 0; j < onesLen; ++j) {
                for (int k = 0; k <= j; ++k) {
                    int onesCnt = onesLen - (j - k + 1);
                    int costDiff = fullcost - (ones[j] - ones[k] + 1);
                    improvements[onesCnt] = std::max(improvements[onesCnt], costDiff);
                }
            }

            for (int j = maxk; j > 0; --j) {
                for (int k = 1; k <= std::min(onesLen, j); ++k) {
                    dp[j] = std::max(dp[j], dp[j - k] + improvements[k]);
                }
            }
        }
    }

    std::cout << tot - dp[maxk] << '\n';

    return 0;
}