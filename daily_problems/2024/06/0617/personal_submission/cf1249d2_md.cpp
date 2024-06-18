// 0617
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    
    constexpr int MAXN = 2e5 + 1;
    std::vector<std::vector<int>> seg_left(MAXN);
    std::vector<std::vector<int>> seg_right(MAXN);
    std::vector<std::pair<int, int>> segs(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        segs[i] = {l, r};
        seg_left[l].push_back(i);
        seg_right[r].push_back(i);
    }

    std::map<int, std::vector<int>> cur_segs;
    std::vector<int> ret;
    int cnt = 0;
    for (int cur_val = 1; cur_val < MAXN; ++cur_val) {
        for (auto idx : seg_left[cur_val]) {
            auto r = segs[idx].second;
            cur_segs[r].push_back(idx);
            ++cnt;
        }

        while (cnt > k) {
            auto it = rbegin(cur_segs);
            if (size(it->second) == 0) {
                cur_segs.erase(it->first);
                continue;
            }

            auto idx = it->second.back();
            it->second.pop_back();
            ret.push_back(idx);
            --cnt;
        }

        while (size(cur_segs) > 0 && begin(cur_segs)->first <= cur_val) {
            cnt -= size(begin(cur_segs)->second);
            cur_segs.erase(begin(cur_segs));
        }
    }

    std::cout << size(ret) << '\n';
    for (auto idx : ret) {
        std::cout << idx + 1 << ' ';
    }
    std::cout << '\n';

    return 0;
}