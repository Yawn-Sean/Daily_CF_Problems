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
    int n;
    cin >> n;
    vector<double> d(n), p(n);
    rep(i, 0, n - 1) cin >> d[i];
    rep(i, 0, n - 1) cin >> p[i];
    double l = 0, r = 1e18, mid;
    auto check = [&](double mid) -> bool {
        double tem = mid;
        frep(i, n - 1, 0) { tem = p[i] * min(1 + tem, d[i]) + (1 - p[i]) * (1 + tem); }
        return tem <= mid;
    };
    rep(i, 0, 199) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(15) << l << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
