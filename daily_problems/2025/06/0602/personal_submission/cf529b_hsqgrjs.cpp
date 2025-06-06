#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> h(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> h[i];
    }

    auto check = [&](int x) -> i64 {
        i64 sum = 0;
        int total = n / 2;
        std::vector<int> tmp;
        for(int i = 0; i < n; i++) {
            if(h[i] > x and w[i] > x) return -1;
            if(h[i] <= x and w[i] <= x) {
                if(h[i] > w[i]) {
                    sum += w[i];
                } else {
                    sum += w[i];
                    tmp.push_back(w[i] - h[i]);
                }
            } else {    
                if(h[i] > x) {
                    sum += h[i];
                    --total;
                } else {
                    sum += w[i];
                }
            }
        }
        if(total < 0) return -1;
        std::sort(tmp.begin(), tmp.end());
        for(int i = tmp.size() - 1; i >= 0 && total > 0; i--) {
            sum -= tmp[i];
            total--;
        }
        return sum;
    };

    i64 ans = 1E18;
    for(int i = 1; i<= 1000; i++) {
        i64 t = check(i);
        if(t != -1) {
            if(ans > t * i) ans = t * i, std::cerr << i << "\n";
        }
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
