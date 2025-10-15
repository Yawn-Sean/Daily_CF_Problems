// 1112
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string input;
    std::cin >> input;

    std::vector<int> packmans, asterisks;
    for (int i = 0; i < n; ++i) {
        if (input[i] == 'P') {
            packmans.push_back(i);
        } else if (input[i] == '*') {
            asterisks.push_back(i);
        }
    }

    auto cando = [&](auto maxTime) {
        int packmanIdx = 0;
        int asteriskIdx = 0;
        while (packmanIdx < std::ssize(packmans)) {
            if (asteriskIdx >= std::ssize(asterisks)) {
                return true;
            }

            auto dis = packmans[packmanIdx] - asterisks[asteriskIdx];
            if (dis > maxTime) {
                return false;
            } else if (dis < -maxTime) {
                ++packmanIdx;
                continue;
            }

            auto leftDis = std::max(0, packmans[packmanIdx] - asterisks[asteriskIdx]);
            // 2 left + right = max or 2 right + left = max
            auto rightDis = packmans[packmanIdx] + std::max(maxTime - 2 * leftDis, (maxTime - leftDis) / 2);
            while (asteriskIdx < std::ssize(asterisks) && asterisks[asteriskIdx] <= rightDis) {
                ++asteriskIdx;
            }

            ++packmanIdx;
        }
        return asteriskIdx == std::ssize(asterisks);
   };

    int low = 0;
    int high = 2 * n;
    while (low + 1 < high) {
        auto mid = low + (high - low) / 2;
        if (cando(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    if (cando(low)) {
        std::cout << low << std::endl;
    } else {
        std::cout << high << std::endl;
    }

    return 0;
}