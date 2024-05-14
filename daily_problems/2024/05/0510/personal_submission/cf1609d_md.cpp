// 0510
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct DSU {
private:
    std::vector<int> f;
    std::vector<int> siz;
public:    
    explicit DSU(int n) noexcept : f(n), siz(n, 1) {
         std::iota(std::begin(f), std::end(f), 0); 
    }
    int leader (int x) noexcept {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }
    bool merge(int x, int y) noexcept {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            siz[x] += siz[y];
            f[y] = x;
        } else {
            siz[y] += siz[x];
            f[x] = y;
        }
        return true;
    }
    bool same(int x, int y) noexcept { return leader(x) == leader(y); }
    int size(int x) noexcept { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    DSU dsu(n);
    vector<int> ret;
    vector<int> cnt_of_size(n + 1);
    cnt_of_size[1] = n;
    int global_tot = 1;
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        if (dsu.leader(x) != dsu.leader(y)) {
            --cnt_of_size[dsu.size(x)];
            --cnt_of_size[dsu.size(y)];
            dsu.merge(x, y);
            ++cnt_of_size[dsu.size(x)];
        } else {
            ++global_tot;
        }
        
        int tot = global_tot;
        int ans = 0;
        for (int comp_siz = n; comp_siz > 0; --comp_siz) {
            if (tot == 0) {
                break;
            }

            int comp = min(tot, cnt_of_size[comp_siz]);
            ans += comp * comp_siz;
            tot -= comp;
        }
        ret.push_back(ans - 1);
    }

    for (auto max_siz : ret) {
        cout << max_siz << "\n";    
    }

    return 0;
}