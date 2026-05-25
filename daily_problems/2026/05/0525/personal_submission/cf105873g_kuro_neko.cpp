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
    ll n, s;
    cin >> n >> s;
    s *= 2;
    if (s < n - 2) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    ll tem = s - (n - 3);
    vector<pll> ma;
    ma.emplace_back(0, 0);
    ma.emplace_back(tem, 0);
    ma.emplace_back(0, 1);
    if (n == 3) {
        for (auto& p : ma) cout << p.first << ' ' << p.second << endl;
        return;
    }
    ma.emplace_back(-1, 1);
    rep(i, 1, n - 4) {
        int tem2 = (i + 1) / 2;
        if (i % 2 == 1)
            ma.emplace_back(-(2 * tem2 + 1), 2);
        else
            ma.emplace_back(-(tem2 + 1), 1);
    }
    for (auto& p : ma) cout << p.first << ' ' << p.second << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
