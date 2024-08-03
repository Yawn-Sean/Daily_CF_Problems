#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
 
struct DSU {
    std::vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) {std::iota(p.begin(), p.end(), 0);}
    int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
};
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n, d;
    std::cin >> n >> d;
 
    DSU g(n);
 
    int c = 1;
    while (d--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (!g.unite(x, y)) {
            c++;
        }
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            if (g.find(i) == i) {
                v.push_back(g.sz[i]);
            }
        }
        std::sort(v.begin(), v.end(), std::greater<int>());
        std::cout << std::accumulate(v.begin(), v.begin() + c, 0) - 1 << '\n';
    }    
 
    return 0;
}
