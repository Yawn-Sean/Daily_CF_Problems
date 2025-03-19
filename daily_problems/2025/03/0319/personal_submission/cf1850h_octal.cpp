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
    vector<ll> dis;
    DSU(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n+1, 1);
        e.resize(n+1);
        f.resize(n+1);
        dis.resize(n+1);
    }
    int get(int x) {
        if(fa[x] != x) {
            int u = get(fa[x]);
            dis[x] += dis[fa[x]];
            fa[x] = u;
        }
        return fa[x];
    }
    bool merge(int x, int y, int d) { // 设x是y的祖先
        ll t = d + dis[y] - dis[x];
        x = get(x), y = get(y);
        dis[x] = t;
        fa[x] = y;
        return true;
    }
};
inline void solve()
{   
    int n, m;
    cin >> n >> m;
    DSU dsu(n+1);
    vector<int> a(m+1), b(m+1), d(m+1);
    for(int i=1; i<=m; i++) {
        cin >> a[i] >> b[i] >> d[i];
    }
    for(int i=1; i<=m; i++) {
        int fa = dsu.get(a[i]);
        int fb = dsu.get(b[i]);
        if(fa == fb && dsu.dis[a[i]] - dsu.dis[b[i]] != d[i]) {
            cout << "NO" << endl;
            return;
        }
        if(fa != fb) {
            dsu.merge(a[i], b[i], d[i]);
        }
    }
    cout << "YES" << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
