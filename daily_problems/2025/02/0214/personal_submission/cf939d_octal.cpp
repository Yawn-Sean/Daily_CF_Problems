#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
struct DSU {
    vector<int> fa, p, e, f;
    DSU(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n+1, 1);
        e.resize(n+1);
        f.resize(n+1);
    }
    int get(int x) {
        while(x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { // 设x是y的祖先
        if(x == y)
            f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if(x == y)
            return false;
        if(x < y)
            swap(x, y); // 将编号小的合并到大的上
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    bool F(int x) { // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x) { // 输出连通块中点的数量
        return p[get(x)];
    }
    int E(int x) { // 输出连通块中边的数量
        return e[get(x)];
    }
};
inline void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    DSU dsu(128);
    set<pair<char, char>> st;
    for(int i=0; i<n; i++) {
        char x = a[i];
        char y = b[i];
        if(!dsu.same(x, y)) {
            st.insert({x, y});
            dsu.merge(x, y);
        }
    }
    cout << st.size() << endl;
    for(auto [x, y]: st)
        cout << x << " " << y << endl;
}
