// 1120
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h;
    i64 n;
    std::cin >> h >> n;

    // curStep: left: 0, right: 1
    auto dfs = [&](auto&& self, i64 left, i64 right, int curStep, int height) -> i64 {
        if (height == 0) {
            return 0;
        }

        auto mid = (left + right) / 2;
        i64 ret = 0;
        if (n <= mid) {
            // from right
            if (curStep == 1) {
                ret = (1ll << height);
            } else {
                ret = 1;
            }
            ret += self(self, left, mid, 1, height - 1);
        } else {
            // from right
            if (curStep == 1) {
                ret = 1;
            } else {
                ret = (1ll << height);
            }
            ret += self(self, mid + 1, right, 0, height - 1);
        }
        return ret;
    };

    std::cout << dfs(dfs, 1, (1ll << h) - 1, 0, h);

    return 0;
}