
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 1e18;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) std::swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    map<int,vector<int> > row, col;
    vector<int> x(n), y(n), t(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> x[i] >> y[i] >> t[i];
        row[x[i]].emplace_back(i);
        col[y[i]].emplace_back(i);
    }

    DSU componet(n+1);
    for (auto &[_, v]: row) {
        sort(all(v), [&](int i, int j) {return y[i] < y[j];});
        int len = SZ(v);
        for (int i = 1; i < len; i ++ ) {
            if (y[v[i]] - y[v[i-1]] <= k) {
                componet.merge(v[i], v[i-1]);
            }
        }
    }
    for (auto &[_, v]: col) {
        sort(all(v), [&](int i, int j) {return x[i] < x[j];});
        int len = SZ(v);
        for (int i = 1; i < len; i ++ ) {
            if (x[v[i]] - x[v[i-1]] <= k) {
                componet.merge(v[i], v[i-1]);
            }
        }
    }


    vector<int>  min_time(n, inf);
    for (int i = 0; i < n; i ++ ) {
        int p = componet.leader(i);
        min_time[p] = min(min_time[p], t[i]);
    }

    vector<int> res;
    for (int i = 0; i < n; i ++ ) {
        if (min_time[i] != inf ) {
            res.emplace_back(min_time[i]);
        }
    }

    sort(all(res));
    int len = SZ(res);
    int ans = len - 1;
    for (int i = 0; i < len; i ++ ) {
        ans = min(ans, max(res[i], len - i - 2));
    }

    cout << ans << endl;

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}