#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
 
void solve() {
    const int M = 2e5 + 10;
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> nums(N), suf(M), cnt(M);

    for (int i = 0; i < N; i ++ ) {
        std::cin >> nums[i];
        suf[nums[i]] = i, cnt[nums[i]] ++;
    }

    int res = 0, l = 0, r = 0, ma = 0;

    for (int i = 0; i < N; i ++ ) {
        if (r < i) {
            res += r - l + 1 - ma;
            ma = 0;
            l = r = i;
        }
        // std::cout << l << " " << r << '\n';
        if (suf[nums[i]] > r) r = suf[nums[i]];
        if (cnt[nums[i]] > ma) ma = cnt[nums[i]];
    }
    res += r - l + 1 - ma;

    std::cout << res;
    /*
        最终状态为若干段相同数字，且任意两段数字不同
        连锁反应——有交集都会变一样
        合并区间即可，区间成本易得
    */
}
 
 
int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}