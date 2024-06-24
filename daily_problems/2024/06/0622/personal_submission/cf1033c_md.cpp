// 0622
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(a));
    std::transform(std::begin(a), std::end(a), std::begin(a), [](int x) { return x - 1; });
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }

    std::vector<int> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        int ai = i + 1;
        for (int j = pos[i] % ai; j < n; j += ai) {
            if (a[j] > i && dp[j] == 0) {
                dp[pos[i]] = 1;
            }
        }
    }

    std::string ret(n, '#');
    std::transform(begin(dp), end(dp), begin(ret), [](int x) { return x ? 'A' : 'B'; });
    std::cout << ret << '\n';
    return 0;
}