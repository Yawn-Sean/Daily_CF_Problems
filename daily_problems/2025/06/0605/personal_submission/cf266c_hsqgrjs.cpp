#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

std::string out;
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n - 1);
    for(int i = 0; i < n - 1; i ++) std::cin >> a[i].first >> a[i].second;
    std::vector<std::tuple<int, int, int>> ans;
    
    bool col[n + 1] = {0};
    for(auto [x, y] : a) col[y] = 1;
    for(auto [x, y] : a) {
        int l = -1;
        for(int i = 1; i < y; i++) {
            if(!col[i]) {
                l = i;
                break;
            }
        }
        if(l > 0 ) {
            ans.push_back({2, l, y});
            for(auto& [x1, y1] : a) {
                if(y1 == y) {
                    y1 = l;
                }
            }
            col[y] = 0;
            col[l] = 1;
        }
    } 

    std::vector<std::pair<int, int>> b;
    bool row[n + 1] = {0};
    
    std::sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second > y.second;
    });
    for(auto [x, y] : a) {
        if(!row[x]) {
            b.push_back({x, y});
            row[x] = 1;
        }
    }
    a = std::move(b);
    int t1 = 1;
    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i].first > t1) {
            // swap(a[i].first, t1);
            int t2 = a[i].first;
            ans.push_back({1, t2, t1});
            for(int j= 0; j < a.size(); j++) {
                if(a[j].first == t1) a[j].first = t2;
                else if(a[j].first == t2) a[j].first = t1;
            }
        }
        
        while(i - 1 >= 0 && a[i - 1].first <= t1) {
            i--;
        }
        t1++;
    }
    int t2 = n - t1 + 1;
    if(t2 > 0) {
        for(int i = t1 - 1; i >= 1; i--) {
            ans.push_back({1, i, i + t2});
        }
    }
    std::cout << ans.size() << "\n";
    for(auto [x, y, z] : ans) {
        std::cout << x << " " << y << " " << z << "\n";

    }

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
