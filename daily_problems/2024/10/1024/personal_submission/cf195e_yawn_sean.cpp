#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

int mod = 1e9 + 7;
struct unionfind {
  public:
    unionfind() : _n(0) {}
    explicit unionfind(int n) : _n(n), parent_or_size(n, -1), depth(n, 0) {}

    void merge(int a, int b, int w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = search(a), y = search(b);
        int vx = getDepth(a), vy = getDepth(b);

        w += vx;
        if (w >= mod) w -= mod;

        w -= vy;
        if (w < 0) w += mod;

        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        depth[y] = w;
    }

    int search(int a) {
        assert(0 <= a && a < _n);
        int acopy = a, v = 0, tmp;

        while (parent_or_size[a] >= 0) {
            v += depth[a];
            if (v >= mod) v -= mod;
            a = parent_or_size[a];
        }

        while (acopy != a) {
            v -= depth[acopy];
            depth[acopy] += v;
            if (v < 0) v += mod;

            tmp = parent_or_size[acopy];
            parent_or_size[acopy] = a;
            acopy = tmp;
        }
        return a;
    }

    int getDepth(int a) {
        search(a);
        return depth[a];
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
    std::vector<int> depth;
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    unionfind dsu(n);
    int ans = 0;

    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;

        while (k --) {
            int idx, val;
            cin >> idx >> val;
            idx --;

            if (val < 0) val += mod;
            val += dsu.getDepth(idx);
            if (val >= mod) val -= mod;

            ans += val;
            if (ans >= mod) ans -= mod;

            int u = dsu.search(idx);
            dsu.merge(i, u, val);
        }
    }

    cout << ans;

    return 0;
}