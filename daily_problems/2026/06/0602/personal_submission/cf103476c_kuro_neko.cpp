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
constexpr int M = 1e5 + 5;
bool is_prime[M];
vector<int> primes;
auto init = [] {
    ranges::fill(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < M; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < M; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return 0;
}();
// 函数指针在创建时自动调用
void solve() {
    ll n;
    cin >> n;
    vector<pll> ma;
    ll x = n;
    for (auto& p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            ll tem = 0;
            while (x % p == 0) {
                tem++;
                x /= p;
            }
            ma.emplace_back(p, tem);
        }
    }
    if (x > 1) ma.emplace_back(x, 1);
    if (sz(ma) == 1) {
        cout << 2 << endl;
        cout << 1 << ' ' << ma[0].first << endl;
        return;
    }
    int m = sz(ma);
    vl cnt(m);
    rep(i, 0, m - 1) cnt[i] = ma[i].second + 1;
    vvi tem;
    rep(i, 0, cnt[0] - 1) tem.push_back({i});
    rep(i, 1, m - 2) {
        auto tem2 = tem;
        vvi tem3;
        rep(j, 0, cnt[i] - 1) {
            if (j % 2 == 0) {
                rep(v, 0, sz(tem2) - 1) {
                    auto p = tem2[v];
                    p.push_back(j);
                    tem3.push_back(p);
                }
            } else {
                frep(v, sz(tem2) - 1, 0) {
                    auto p = tem2[v];
                    p.push_back(j);
                    tem3.push_back(p);
                }
            }
        }
        tem = tem3;
    }
    ll m1 = sz(tem), m2 = cnt[m - 1];
    vector<pii> tem2;
    if (m1 * m2 % 2 == 0) {
        if (m1 % 2 == 0) {
            rep(i, 0, m2 - 1) tem2.push_back({0, i});
            rep(i, 1, m1 - 1) {
                if (i % 2 == 1) {
                    frep(j, m2 - 1, 1) tem2.push_back({i, j});
                } else {
                    rep(j, 1, m2 - 1) tem2.push_back({i, j});
                }
            }
            frep(i, m1 - 1, 1) tem2.push_back({i, 0});
        } else {
            rep(i, 0, m1 - 1) tem2.push_back({i, 0});
            rep(i, 1, m2 - 1) {
                if (i % 2 == 1) {
                    frep(j, m1 - 1, 1) tem2.push_back({j, i});
                } else {
                    rep(j, 1, m1 - 1) tem2.push_back({j, i});
                }
            }
            frep(i, m2 - 1, 1) tem2.push_back({0, i});
        }
    } else {
        tem2.push_back({1, 0});
        for (int i = 1; i < m2; i += 2) {
            tem2.push_back({1, i});
            tem2.push_back({0, i});
            tem2.push_back({0, i + 1});
            tem2.push_back({1, i + 1});
        }
        rep(i, 2, m1 - 1) {
            if (i % 2 == 0) {
                frep(j, m2 - 1, 1) tem2.push_back({i, j});
            } else {
                rep(j, 1, m2 - 1) tem2.push_back({i, j});
            }
        }
        frep(i, m1 - 1, 2) tem2.push_back({i, 0});
    }
    vl ans;
    for (auto& [x, y] : tem2) {
        vi tem3 = tem[x];
        tem3.push_back(y);
        ll tem4 = 1;
        rep(i, 0, m - 1) { rep(j, 1, tem3[i]) tem4 *= ma[i].first; }
        ans.push_back(tem4);
    }
    cout << sz(ans) << endl;
    rep(i, 0, sz(ans) - 1) cout << ans[i] << ' ';
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
