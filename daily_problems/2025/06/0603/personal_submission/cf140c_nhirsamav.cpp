//  C. New Year Snowmen
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
using arr3  = std::array<i32,3>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::map<i32,i32> m;
    for (i32 i = 0;i<n;i++) {
        i32 x;
        std::cin>>x;
        m[x]++;
    }
    std::priority_queue<arr3> p;
    for (auto [x,y] : m) {
        p.push({y,x});
    }
    std::vector<std::array<i32,3>> ans;
    while (p.size()>=3) {
        arr3 a = p.top();
        p.pop();
        arr3 b = p.top();
        p.pop();
        arr3 c = p.top();
        p.pop();
        ans.push_back({a[1],b[1],c[1]});
        if (--a[0]) p.push(a);
        if (--b[0]) p.push(b);
        if (--c[0]) p.push(c);
    }
    std::cout<<ans.size()<<endl;
    for (auto &a:ans) {
        std::ranges::sort(a,std::greater<>());
        std::cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
