// 0709
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string c, a;
    std::cin >> c >> a;
    auto target = std::count(begin(a), end(a), '1');

    std::vector<std::vector<int>> cnt(3);
    for (int i = 0; i < n; ++i) {
        int v = c[i] - '0' + a[i] - '0';
        cnt[v].push_back(i + 1);
    }

    std::vector<int> pick(3);
    for (pick[2] = 0; pick[2] <= ssize(cnt[2]); ++pick[2]) {
        pick[1] = target - pick[2] * 2;
        pick[0] = n / 2 - pick[1] - pick[2];
        if (pick[0] >= 0 && pick[0] <= ssize(cnt[0]) && pick[1] >= 0 && pick[1] <= ssize(cnt[1])) {
            std::vector<int> ans;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < pick[i]; ++j) {
                    ans.push_back(cnt[i][j]);
                }
            }

            if (size(ans) == n / 2) {
                for (auto num : ans) {
                    cout << num << ' ';
                }
                std::cout << '\n';
                return 0;
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}