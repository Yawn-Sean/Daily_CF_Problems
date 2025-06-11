// 0909
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, w, q;
    std::cin >> n >> w >> q;
    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }

    auto strToBin = [](const std::string& s) {
        int val = 0;
        for (char ch : s) {
            val = val * 2 + (ch - '0');
        }
        return val;
    };

    std::vector<int> w_cnt(1 << n);
    for (int i = 0; i < w; ++i) {
        std::string s;
        std::cin >> s;
        ++w_cnt[strToBin(s)];
    }

    auto bitToScore = [&](int mask) {
        int score = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> n - i - 1) & 1) {
                score += scores[i];
            }
        }
        return score;
    };
    
    std::vector<std::vector<int>> dp(101, std::vector<int>(1 << n));
    for (int mask_for_query = 0; mask_for_query < (1 << n); ++mask_for_query) {
        for (int mask_for_w = 0; mask_for_w < (1 << n); ++mask_for_w) {
            auto same_bits = (1 << n) - 1 - (mask_for_query ^ mask_for_w);
            auto score = bitToScore(same_bits);
            if (score <= 100) {
                dp[score][mask_for_query] += w_cnt[mask_for_w];
            }
        }
        
        for (int score = 1; score <= 100; ++score) {
            dp[score][mask_for_query] += dp[score - 1][mask_for_query];
        }
    }

    std::vector<std::pair<int, int>> qs(q);
    for (int i = 0; i < q; ++i) {
        std::string s;
        int max_val;
        std::cin >> s >> max_val;
        std::cout << dp[max_val][strToBin(s)] << '\n';
    }

    return 0;
}