#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

const int P = [](int x) {
    auto isprime = [](int x) {
        if (x <= 1) return false;
        for (int i = 2; i <= x / i; i ++ )
            if (x % i == 0) return false;
        return true;
    };
    while (!isprime(x)) x ++;
    return x;
}(rnd() % 900000000 + 100000000);

void solve() {
    /*  直接模拟    */
    int N, Q, s;
    std::cin >> N >> Q;
    std::vector<int> nums(N);
    std::vector<i64> pre(N + 1);
    for (int i = 0; i < N; i ++ ) 
        std::cin >> nums[i];
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i ++ ) 
        pre[i + 1] += nums[i] + pre[i];
    
    std::vector<std::array<int, 2>> segs { { 0, N - 1 } };  segs.reserve(N);
    std::unordered_set<i64> st;

    while (segs.size()) {
        std::vector<std::array<int, 2>> nxt;
        for (auto& [l, r] : segs) {
            st.insert(pre[r + 1] - pre[l] + P);

            if (nums[l] != nums[r]) {
                int mid = std::upper_bound(nums.begin(), nums.end(), (nums[l] + nums[r]) >> 1) - nums.begin();
                nxt.insert(nxt.end(), { { l, mid - 1 }, { mid, r } });
            }
        }
        segs = std::move(nxt);
    }

    for (int i = 0, s; i < Q; i ++) {
        std::cin >> s;
        if (st.count(1LL * s + P))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}


int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}