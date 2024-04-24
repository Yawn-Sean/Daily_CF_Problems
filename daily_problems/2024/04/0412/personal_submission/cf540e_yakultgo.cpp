#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
class FenwickTree {
private:
    vector<long long> tr;

public:
    FenwickTree(int n) : tr(n + 10, 0) {}
    static inline int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int delta) {
        while (x < tr.size()) {
            tr[x] += delta;
            x += lowbit(x);
        }
    }
    long long query(int x) {
        long long res = 0;
        while (x > 0) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert(x);
        st.insert(y);
        if (!mp.count(x)) mp[x] = x;
        if (!mp.count(y)) mp[y] = y;
        swap(mp[x], mp[y]);
    }
    int cnt = 0;
    map<int, int> rank;
    map<int, int> w;
    int pre = 1;
    for (auto &x : st) {
        rank[x] = 2 * (++cnt);
        w[x] = x - pre;
        pre = x + 1;
    }
    FenwickTree tr(2 * cnt);
    ll ans = 0;
    for (auto &x : st) {
        // 找比rank[x] - 1大的数
        ans += (tr.query(2 * cnt) - tr.query(rank[x] - 1)) * w[x];
        tr.add(rank[x] - 1, w[x]);
        // 找比rank[mp[x]]大的数
        ans += tr.query(2 * cnt) - tr.query(rank[mp[x]]);
        tr.add(rank[mp[x]], 1);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}