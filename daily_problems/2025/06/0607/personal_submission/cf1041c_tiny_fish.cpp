#include <bits/stdc++.h>

using std::cin, std::cout, std::ios;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, d; cin >> n >> m >> d;
    std::vector < std::pair <int, int> > a(n); for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;

    std::sort(a.begin(), a.end());

    int sz = 1;
    std::vector <int> ans(n);
    std::priority_queue < std::pair <int, int> > q; q.emplace(m + 1, 1);

    for(int i = 0; i < n; i++) {
        auto [lst, idx] = q.top(); lst *= -1; 
        if(a[i].first - lst <= d) {
            sz ++;
            ans[a[i].second] = sz;
            q.emplace(-a[i].first, sz);
        } else {
            q.pop(); 
            ans[a[i].second] = idx; 
            q.emplace(-a[i].first, idx);
        }
    }

    cout << sz << '\n';
    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];

    return 0;
}