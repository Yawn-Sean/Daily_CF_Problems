#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    char op;
    int x, y, n, q;
    cin >> n >> q;
    vvi ma(n, vi(n));
    vi r(n), c(n);
    rep(i, 0, n - 1) { r[i] = i, c[i] = i; }
    rep(i, 0, q - 1) {
        cin >> op >> x >> y;
        x--, y--;
        if (op == 'R')
            swap(r[x], r[y]);
        else
            swap(c[x], c[y]);
    }
    vi rn(n), rp(n);
    vi cn(n), cp(n);
    int tem = -1;
    auto dfs = [&](vi& r, vi& rn, vi& rp) -> bool {
        vi vis(n);
        int tem2 = 0;
        rep(i, 0, n - 1) {
            if (vis[i]) continue;
            vi tem3;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                tem3.push_back(cur);
                cur = r[cur];
            }
            if (tem == -1) tem = sz(tem3);
            if (tem != sz(tem3)) return false;
            rep(j, 0, sz(tem3) - 1) {
                rn[tem3[j]] = tem2;
                rp[tem3[j]] = j;
            }
            tem2++;
        }
        return true;
    };
    if (!dfs(r, rn, rp) || !dfs(c, cn, cp)) {
        cout << "*" << endl;
        return;
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { ma[i][j] = (rn[i] + cn[j]) % (n / tem) * tem + (rp[i] - cp[j] + tem) % tem + 1; }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) cout << ma[i][j] << ' ';
        cout << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
