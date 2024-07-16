#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;

constexpr double eps = 1e-12;
/*
    sum{a}= n
    strictly increasing
    a_{i} <= 2a_{i-1}

    所有长度为k sum < n 的acsending序列中是否有合法的？
    a0 = d = 1, 满足规则2、3，不一定满足1
    如果 > n, 直接NO
    否则，加数

    先加(sum - n) / k
    然后看余数
    余数可以拆成小于k个1，此时只需看倒着加了后会不会违反规则3
*/
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k);
    std::iota(a.begin(), a.end(), 1);   
    i64 s = (1LL + k) * k / 2;
    if (s > n) {
        std::cout << "NO\n";
        return;
    }
    int delta = (n - s) / k, res = (n - s) % k;
    auto check = [&]() -> bool {
        for (int i = 0; i < k; ++ i) 
            a[i] += delta;
        bool f = true;
        while (f) {
            f = false;
            for (int i = 1; i < k && res; ++ i)
                if (a[i] + 1 < (i + 1 < k ? a[i + 1] : 1e18) && a[i] + 1 <= a[i - 1] * 2)
                    -- res, ++ a[i], f = true;
        }
        return !res;
    };
    if (check()) {
        std::cout << "YES\n";
        for (int i = 0; i < k; ++ i) 
            std::cout << a[i] << " \n"[i == n - 1];
    }
    else
        std::cout <<"NO\n";
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}