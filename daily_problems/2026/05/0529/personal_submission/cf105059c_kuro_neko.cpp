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
    ll n, m, g, x, y;
    cin >> n >> m >> g;
    vvl ma(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    if (g != 2) {
        cout << 0 << endl;
        return;
    }
    vi co(n);
    auto dfs = [&](this auto&& dfs, int x, int c) -> bool {
        co[x] = c;
        for (auto& p : ma[x]) {
            if (co[p] == c || (co[p] == 0 && !dfs(p, 3 - c))) return false;
        }
        return true;
    };
    cout << (dfs(0, 1) && co[0] != co[n - 1] ? 1 : 0) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
