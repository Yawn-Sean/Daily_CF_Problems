#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

class seg {
#define ls(p)   (p << 1)
#define rs(p)   (p << 1 | 1)

public :
    struct node {
        i64 val;
        int x;
        node() :  val(0) {}
    };
    int n;
    std::vector<node> t;
    
    seg() {}
    seg(std::vector<int>& a, std::vector<i64>& b) : n(a.size()), t((n + 1) << 2, node())
    {
        build(1, 1, n - 1, a, b);
    }

    void update(int p) {
        t[p].val = t[ls(p)].val + t[rs(p)].val;
    }

    void build(int p, int l, int r, std::vector<int>& a, std::vector<i64>& b) {
        // L = l, t[p].r = r;
        if(l == r) {
            t[p].val = a[l] * b[l];
            t[p].x = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(ls(p), l, m, a, b);
        build(rs(p), m + 1, r, a, b);
        update(p);
    }

    void modify(int p, int x, i64 v, int L, int R) {

        if(L == x && x == R) {
            t[p].val /= t[p].x;
            t[p].x = v;
            t[p].val *= v;
            return ;
        }
        int m = (L + R) / 2;
        if(m >= x) modify(ls(p), x, v, L, (L + R) / 2);
        if(m <  x) modify(rs(p), x, v, (L + R) / 2 + 1, R);
        update(p);
    }

    i64 quiry(int p, int l, int r, int L, int R) {
        if(l <= L && R <= r) return t[p].val;
        int m = (L + R) / 2;
        i64 ans = 0;
        if(m >= l) ans += quiry(ls(p), l, r, L, (L + R) / 2);
        if(m <  r) ans += quiry(rs(p), l, r, (L + R) / 2 + 1, R);
        return ans;
    }


#undef ls
#undef rs
};


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    //  2 : 2 , 3 : 4, 4 : 6, 5 : 8 , 6 : 10
    seg S[7][11] = {};
    for (int i = 2; i <= 6; i++) {
        for (int j = 0; j < i * 2 - 2; j++) {
            std::vector<i64> b(n + 1, 0);
            for (int k = j + 1; k <= n; k++) {
                int p = k - j;
                if (p % (2 * i - 2) == 0) {
                    b[k] = 2;
                } else if (p % (2 * i - 2) <= i) {
                    b[k] = p % (2 * i - 2);
                } else {
                    b[k] = 2 * i - p % (2 * i - 2);
                }
            }
            S[i][j + 1] = seg(a, b);
        }
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int p, v;
            std::cin >> p >> v;
            for(int i = 2; i <= 6; i++) {
                for(int j = 1; j <= i * 2 - 2; j++) {
                    S[i][j].modify(1, p, v, 1, n);
                }
            }
        } else {
            int l, r, z;
            std::cin >> l >> r >> z;
            int k = (l - 1) % (2 * z - 2) + 1;
            std::cout << S[z][k].quiry(1, l, r, 1, n) << "\n";                                                                                               
        }
    }

    return 0;
}
