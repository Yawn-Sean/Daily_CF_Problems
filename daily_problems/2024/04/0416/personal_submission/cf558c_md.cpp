#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Built a tree according to the 0-1 bits of the values. Node i has child 2i and 2i+1.
    // The answer is the min distance to all marked nodes from min value. N.B. cannot move from i to 2i + 1.
    
    int n;
    std::cin >> n;
    vector<int> nums(n);
    copy_n(istream_iterator<int>(cin), n, begin(nums));
    int len = *max_element(begin(nums), end(nums));
    
    vector<int> pos(len + 1);
    for (int i = 0; i < n; ++i) {
        pos[nums[i]]++;
    }

    vector<int> siz = pos;
    constexpr auto root = 1;
    auto find_siz = [&](auto self, int cur) {
        if (cur > len) {
            return;
        }
        for (int next = cur * 2; next <= cur * 2 + 1; ++next) {
            if (next <= len) {
                self(self, next);
                siz[cur] += siz[next];
            }
        }
    };
    find_siz(find_siz, root);
    auto start = len - (find(rbegin(siz), rend(siz), n) - rbegin(siz));

    vector<int> depth(len + 1, 0);
    vector<i64> ans(len + 1, 0);
    auto dfs = [&](auto self, int cur) {
        if (cur > len) {
            return;
        }

        ans[start] += (depth[cur] * pos[cur]);
        for (int next = cur * 2; next <= cur * 2 + 1; ++next) {
            if (next <= len) {
                depth[next] = depth[cur] + 1;
                self(self, next);
            }
        }
    };
    dfs(dfs, start);

    i64 ret = numeric_limits<i64>::max();
    auto dfs2 = [&](auto self, int cur) {
        if (cur > len) {
            return;
        }

        int next = cur * 2;
        if (next <= len) {
            ans[next] = ans[cur] + siz[start] - 2ll * siz[next];
            self(self, next);
        }
        ret = min(ret, ans[cur]);
    };
    dfs2(dfs2, start);

    cout << ret << endl;
    return 0;
}