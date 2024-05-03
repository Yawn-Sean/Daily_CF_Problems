// 0503
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::map<int, int> streak_freq;
    std::map<int, int> value_freq{{0, 1}};
    int max_streak_len = 0;
    int ret = 0;

    for (auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (streak_freq.contains(value_freq[x])) {
            if (--streak_freq[value_freq[x]] == 0) {
                streak_freq.erase(value_freq[x]);
            }
        }
        streak_freq[++value_freq[x]]++;
 
        if (size(streak_freq) == 1 && (streak_freq.begin()->first == 1 || streak_freq.begin()->second == 1)) {
            ret = max(ret, i + 1);
        } else if (size(streak_freq) == 2 && streak_freq.contains(1) && streak_freq[1] == 1) {
            ret = max(ret, i + 1);
        } else if (size(streak_freq) == 2 && streak_freq.rbegin()->second == 1 && 
            streak_freq.begin()->first + 1 == streak_freq.rbegin()->first) {
            ret = max(ret, i + 1);
        }
    }

    std::cout << ret << endl;
    return 0;
}