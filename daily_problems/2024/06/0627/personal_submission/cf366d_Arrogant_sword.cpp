
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int> vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int M = 3e3 + 10;
const int N = 1e3 + 10;
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

struct Edge
{
    int u, v, l, r;
}e[M];
int L[M];
int ans = 0;
int n, m;

bool check(int l, int r) {
    
    DSU component(n+1);
    rep(i, m) {
        if (e[i].l <= l && e[i].r >= r ) {
            component.merge(e[i].u, e[i].v);
            
        }
    }

    if (!component.merge(1, n)) {
        ans = max(ans, r - l + 1);
        return true;
    }
    return false;
}

void solve(int _) 
{
    
    cin >> n >> m;
    rep(i, m) {
        cin >> e[i].u >> e[i].v >> e[i].l >> e[i].r;
        L[i] = e[i].l;
    }

    sort(L + 1, L + 1 + m);
    rep(i, m) {
        int l = L[i], r = 1e6+10;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(L[i], mid)) l = mid;
            else r = mid - 1;
        }
        check(l, r);
    }

    if (ans > 0) {
        cout << ans;
    } else {
        cout << "Nice work, Dima!";
    }
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}