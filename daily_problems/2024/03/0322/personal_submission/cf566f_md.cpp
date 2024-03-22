#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;

constexpr int V = 1e6 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(a));
    int max_e = *std::max_element(begin(a), end(a));

    std::vector<int> dp(max_e + 1);
    int ret = 0;
    for (auto val : a) {
        dp[val]++;
        for (int j = 2; j <= max_e / val; ++j) {
            dp[j * val] = std::max(dp[j * val], dp[val]);
        }
        ret = std::max(ret, dp[val]);
    }

    std::cout << ret << "\n";
    return 0;
}