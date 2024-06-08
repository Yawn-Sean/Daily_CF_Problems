#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
 
class UnionFindSet {
private:
    std::vector<int> p, w;
    int n;
public:
    UnionFindSet(int _n, std::vector<int> _w) : p(_n, -1), w(_w), n(_n) {}
    
    int find(int x) {
        if (p[x] < 0) return x;
        p[x] = find(p[x]);
        w[p[x]] = std::min(w[p[x]], w[x]);
        return p[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (p[px] > p[py]) std::swap(px, py);
        w[px] = std::min(w[px], w[py]);
        p[px] += p[py], p[py] = px;
    }

    int value(int p) const {
        return w[p];
    }
};

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::array<int, 2>> pos(N);
    std::vector<int> w(N);
    std::map<int, std::vector<int>> xs, ys;

    for (int i = 0; i < N; i ++ ){
        std::cin >> pos[i][0] >> pos[i][1] >> w[i];
        xs[pos[i][0]].push_back(i);
        ys[pos[i][1]].push_back(i);
    }

    for (auto& p : xs) 
        std::sort(p.second.begin(), p.second.end(), [&](int x, int y) {
            return pos[x][1] < pos[y][1];
        });

    for (auto& p : ys) 
        std::sort(p.second.begin(), p.second.end(), [&](int x, int y) {
            return pos[x][0] < pos[y][0];
        });



    UnionFindSet ufs(N, w);

    for (auto& p : xs) {
        for (auto it = p.second.begin(); it != p.second.end(); it ++) {
            auto nxt = std::next(it);
                
            if (nxt != p.second.end() && pos[*nxt][1] - pos[*it][1] <= K) 
                ufs.merge(*it, *nxt);
        }
    }

    for (auto& p : ys) {
        for (auto it = p.second.begin(); it != p.second.end(); it ++) {
            auto nxt = std::next(it);
            if (nxt != p.second.end() && pos[*nxt][0] - pos[*it][0] <= K) 
                ufs.merge(*it, *nxt);
        }
    }

    std::vector<int> values; values.reserve(N);

    for (int i = 0; i < N; i ++ ) {
        int pi = ufs.find(i);
        if (pi == i) values.push_back(ufs.value(pi));
    }

    std::sort(values.begin(), values.end(), std::greater<int>());

    int res = 1e9;

    for (int i = 0; i < values.size(); i ++ ) 
        res = std::min( { res, std::max(i, i + 1 < values.size() ? values[i + 1] : 0) } );
    
    std::cout << res << '\n';
    /*
        可以得到若干连通块
        每个连通块的最小时间的最大值
    */
}
 
 
int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}