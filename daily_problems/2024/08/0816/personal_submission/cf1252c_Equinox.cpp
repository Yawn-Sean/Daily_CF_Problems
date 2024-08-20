#include <bits/stdc++.h>

void solve(){  
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++ i) {
        std::cin >> b[i];
    }
    
    std::vector<int> acc1(n), acc2(n);
    for (int i = 1; i < n; ++ i) {
        acc1[i] = (a[i] % 2 == a[i - 1] % 2 ? acc1[i - 1] : i);
        acc2[i] = (b[i] % 2 == b[i - 1] % 2 ? acc2[i - 1] : i);
    }
    
    for (int i = 0, x1, y1, x2, y2; i < q; ++ i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        -- x1, -- y1, -- x2, -- y2;
        
        if (acc1[x1] == acc1[x2] && acc2[y1] == acc2[y2])
            std::cout << "YES\n";
        else 
            std::cout << "NO\n";
    }
    
}

int main(int argc, char** argv) {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();
    return 0;
}