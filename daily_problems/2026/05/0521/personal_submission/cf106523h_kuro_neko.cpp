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
constexpr int MX = 2e5 + 1;
int lpf[MX];  // 存储每个数的最小素因子，复杂度O(NloglogN)
auto init = [] {
    for (int i = 2; i < MX; i++) {
        if (lpf[i] == 0) {
            for (int j = i; j < MX; j += i) {
                if (lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    return 0;
}();
// 质因数分解，返回值为pair<素因子，素因子次幂>，复杂度O(logN)
vector<pair<int, int>> cnt(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = lpf[x];
        int e = 1;
        for (x /= p; x % p == 0; x /= p) {
            e++;
        }
        res.emplace_back(p, e);
    }
    return res;
}
void solve() {
    ll q, op, x;
    cin >> q;
    map<int, int> ma;
    set<int> s2;
    auto check = [&](vector<pii>& val) {
        for (auto& [a, b] : val) {
            if (s2.count(a)) continue;
            if (!ma.count(a) || ma[a] < b) return false;
        }
        return true;
    };
    rep(i, 0, q - 1) {
        cin >> op >> x;
        if (op == 1) {
            auto val = cnt(x);
            for (auto& [a, b] : val) {
                if (!ma.count(a))
                    ma[a] = b;
                else {
                    ma[a] += b;
                    if (ma[a] > 17) {
                        ma.erase(ma.find(a));
                        s2.insert(a);
                    }
                }
            }
        } else if (op == 2) {
            for (auto it = ma.begin(); it != ma.end();) {
                it->second *= x;
                if (it->second > 17) {
                    s2.insert(it->first);
                    it = ma.erase(it);
                } else
                    it++;
            }
        } else {
            auto val = cnt(x);
            bool flag = check(val);
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
