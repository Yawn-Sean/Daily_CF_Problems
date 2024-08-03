#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> seq(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(seq));

    vector<int> dp(4);
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(4);
        tmp[0] = dp[0] + (seq[i] == 1);
        tmp[1] = max(tmp[0], dp[1] + (seq[i] == 2));
        tmp[2] = max(tmp[1], dp[2] + (seq[i] == 1));
        tmp[3] = max(tmp[2], dp[3] + (seq[i] == 2));
        dp = move(tmp);
    }

    cout << dp[3] << '\n';
    return 0;
}