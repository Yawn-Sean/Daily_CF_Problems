#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, a, b, q;
    std::cin >> n >> k >> a >> b >> q;

    std::vector<int> c(n), d(n);
    Fenwick<int> fen1(n + 5), fen2(n + 5);

    for (int i = 0; i < q; i++) {
        int o;
        std::cin >> o;
        if (o == 1) {
            int x, y;
            std::cin >> x >> y;
            x--;
            
            int v;
            v = std::min(c[x] + y, b) - c[x];
            fen1.add(x, v);
            c[x] += v;

            v = std::min(d[x] + y, a) - d[x];
            fen2.add(x, v);
            d[x] += v;
        } else {
            int x;
            std::cin >> x;
            x--;
            std::cout << fen1.sum(x - 1) + fen2.rangeSum(x + k, n) << "\n";
        }
    }
    
    return 0;
}
