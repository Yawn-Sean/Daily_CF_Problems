// 0703
#include <bits/stdc++.h>
using namespace std;

int fmin(int a, int b) { return std::min(a, b); }
int e() { return std::numeric_limits<int>::max(); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums)); 

    std::vector<std::tuple<int, int, int>> queries;
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        queries.emplace_back(l, r, i);
    }

    std::map<int, int> last_pos;
    std::vector<int> dis(n, n);
    for (int i = 0; i < n; ++i) {
        if (last_pos.contains(nums[i])) {
            dis[i] = i - last_pos[nums[i]];
        }
        last_pos[nums[i]] = i;
    }

    last_pos.clear();
    std::vector<int> next_pos(n, n);
    for (int i = n - 1; i >= 0; --i) {
        if (last_pos.contains(nums[i])) {
            next_pos[i] = last_pos[nums[i]];
        }
        last_pos[nums[i]] = i;
    }

    std::sort(begin(queries), end(queries));

    atcoder::segtree<int, fmin, e> segtree(dis);

    std::vector<int> ret(m);
    int cur = 0;
    for (auto[l, r, idx] : queries) {
        while (cur < l) {
            if (next_pos[cur] < n) {
                segtree.set(next_pos[cur], std::numeric_limits<int>::max());   
            }
            ++cur;
        }
        ret[idx] = segtree.prod(l, r + 1);
    }
    std::transform(std::begin(ret), std::end(ret), std::ostream_iterator<int>(std::cout, "\n"), [n](int x) { return x < n ? x : -1; });
    
    return 0;
}