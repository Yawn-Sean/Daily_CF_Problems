// 0610 
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> notes(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(notes));

    std::map<int, int> cnt;
    for (auto note : notes) {
        for (int i = 1; i <= k; ++i) {
            if (!cnt.contains(i * note) || cnt[i * note] > i) {
                cnt[i * note] = i;
            }
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;

        int ret = std::numeric_limits<int>::max();
        if (cnt.contains(x)) {
            ret = cnt[x];
        }

        for (auto[val, cost] : cnt) {
            int comp_val = x - val;
            if (cnt.contains(comp_val) && cnt[comp_val] + cost <= k) {
                ret = std::min(ret, cnt[comp_val] + cost);
            } 
        }

        if (ret == std::numeric_limits<int>::max()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << ret << "\n";
        }
    }

    return 0;
}