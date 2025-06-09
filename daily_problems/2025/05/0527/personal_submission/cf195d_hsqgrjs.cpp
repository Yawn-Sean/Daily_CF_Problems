#include <bits/stdc++.h>
#include <cfloat>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long double, long double>> a(n + 1);
    int mi = 1E9 + 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].first >> a[i].second;
    }
    int r = n;
    while(a[r].first == 0 && r > 0) r--;
    for(int i = r; i > 0; i--) {
        if(a[i].first == 0) {
            std::swap(a[i], a[r]);
            r--;
        }
    }
    n = r;
	std::sort(a.begin() + 1, a.begin() + r + 1, [] (auto x, auto y){
        return -  x.second / x.first < - y.second / y.first;
    });

    auto get = [&](std::pair<long double, long double> x)->long double {
        return -  x.second / x.first;
    };

    int l = 1, cnt = 0;
    while(l <= r) {
        long double prel = 0, prer = 0;
        while(l + 1 <= r && std::fabs(get(a[l + 1]) - get(a[l])) < LDBL_EPSILON) {
            if(a[l].first >= 0) prel += a[l].first;
            else prer += a[l].first;
            l++;
        }
        if(a[l].first >= 0) prel += a[l].first;
        else prer += a[l].first;
        if(!(prel == 0 && prer == 0)) cnt++;
        l++;
    }
    std::cout << cnt << "\n";
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
