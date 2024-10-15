#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
char s[N + 1];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    vector<vector<int>> dp[2]{};
    bool cant_divide = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (dp[1].empty()) {
                dp[0].push_back({i});
            } else {
                dp[1].back().push_back(i);
                dp[0].emplace_back();
                swap(dp[0].back(), dp[1].back());
                dp[1].pop_back();
            }
        } else {
            if (dp[0].empty()) {
                cant_divide = true;
                break;
            } else {
                dp[0].back().push_back(i);
                dp[1].emplace_back();
                swap(dp[0].back(), dp[1].back());
                dp[0].pop_back();
            }
        }
    }
    if (cant_divide || !dp[1].empty()) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[0].size());
        for (auto& v : dp[0]) {
            printf("%d ", v.size());
            for (auto& i : v) {
                printf("%d ", i + 1);
            }
            printf("\n");
        }
    }
    return 0;
}

