// 0907
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> nums(n);
    std::vector<std::vector<std::string>> hash(n);
    std::map<std::string, int> cnt;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        for (int len = 1; len <= 9; ++len) {
            std::set<std::string> patterns;

            for (int left = 0; left + len <= 9; ++left) {
                std::string sub = nums[i].substr(left, len);
                patterns.insert(sub);
            }

            for (auto pattern : patterns) {
                hash[i].push_back(pattern);
                cnt[pattern]++;
            }
        }

    }
 
    for (int i = 0; i < n; ++i) {
        for (auto& sub : hash[i]) {
            if (cnt[sub] == 1) {
                std::cout << sub << '\n';
                break;
            }
        }
    }


    return 0;
}