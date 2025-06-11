// 0705
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using pii = std::pair<int, int>;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    
    std::map<int, int> intervals;
    int last = -1;
    for (size_t i = 0; i < size(s); ++i) {
        if (s[i] == '.') {
            if (last == -1) {
                last = i;    
            } 
            intervals[last] = i;
        } else {
            last = -1;
        }
    }
 
    int ret = 0;
    for (auto[l, r] : intervals) {
        ret += r - l;
    }
 
    for (int i = 0; i < m; ++i) {
        int x; char c;
        std::cin >> x >> c;
        --x;
 
        auto it = intervals.upper_bound(x);
        if (it != begin(intervals)) {
            it = prev(it);
        }

        if (c == '.' && s[x] != '.') {
            if (it != end(intervals) && it->second == x - 1)
            {
                if (next(it) != end(intervals) && next(it)->first == x + 1) {
                    auto nxt_it = next(it);
                    auto right = nxt_it->second;
                    intervals.erase(nxt_it);
                    ret += std::max(0, right - it->first) - std::max(0, right - (x + 1)) - std::max(0, (x - 1) - it->first);
                    intervals.erase(it);
                    intervals[it->first] = right;
                } else {
                    it->second = x;
                    ++ret;
                }
            } else if (intervals.contains(x + 1)) {
                auto it = intervals.find(x + 1);
                intervals[x] = it->second;
                intervals.erase(it);
                ++ret;
            } else {
                intervals[x] = x;
            }
        } else if (c != '.' && s[x] == '.') { 
            if (it != end(intervals) && it->first <= x && it->second >= x) {
                ret += std::max(0,  x - it->first - 1) + std::max(0, it->second - x - 1) - std::max(0, it->second - it->first);
                if (it->second - x > 0) {
                    intervals[x + 1] = it->second;
                }
 
                if (x - it->first > 0) {
                    it->second = x - 1;
                } else {
                    intervals.erase(it);
                }
            }
        }
 
        s[x] = c;
        std::cout << ret << '\n';
    }
 
 
    return 0;
}
