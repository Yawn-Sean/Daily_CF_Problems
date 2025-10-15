#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::set<int> nodes;
    std::map<int, int> l, r;
    int a;
    std::cin >> a;
    nodes.insert(a);
    for (int i = 0; i < n - 1; i++) {
        int a;
        std::cin >> a;
        auto it = nodes.upper_bound(a);

        int ans = 0;
        if (it != nodes.end() && !l.contains(*it)) {
            l[*it] = a;
            ans = *it;
        } else {
            it = std::prev(it);
            r[*it] = a;
            ans = *it;
        } 
        nodes.insert(a);
        std::cout << ans << " \n"[i == n - 2];
    }
    
    return 0;
}
