#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
class FenwickTree {
private:
    vector<int> tr;

public:
    FenwickTree(int n) : tr(n + 10, 0) {}
    static inline int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int delta) {
        while (x < tr.size()) {
            tr[x] = max(tr[x], delta);
            x += lowbit(x);
        }
    }
    int query(int x) {
        int res = 0;
        while (x > 0) {
            res = max(res, tr[x]);
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<pair<int, int>> ob[2];
    FenwickTree ft1(1e5), ft2(1e5);
    for (int i = 0; i < n; i++) {
        int b, p;
        char t;
        cin >> b >> p >> t;
        if (t == 'C') {
            ob[0].push_back({b, p});
        } else {
            ob[1].push_back({b, p});
        }
    }
    sort(ob[0].begin(), ob[0].end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    sort(ob[1].begin(), ob[1].end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    int ans1 = 0;
    int cnt = 0;
    for (int i = 0; i < ob[0].size(); i++) {
        if (ob[0][i].second <= c) {
            ans1 += ob[0][i].first;
            cnt++;
            break;
        }
    }
    for (int i = 0; i < ob[1].size(); i++) {
        if (ob[1][i].second <= d) {
            ans1 += ob[1][i].first;
            cnt++;
            break;
        }
    }
    if (cnt != 2) ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < ob[0].size(); i++) {
        if (ob[0][i].second <= c) {
            int tmp = ft1.query(c - ob[0][i].second);
            if (tmp != 0)
                ans2 = max(ans2, ob[0][i].first + tmp);
        }
        ft1.add(ob[0][i].second, ob[0][i].first);
    }
    int ans3 = 0;
    for (int i = 0; i < ob[1].size(); i++) {
        if (ob[1][i].second <= d) {
            int tmp = ft2.query(d - ob[1][i].second);
            if (tmp != 0)
                ans3 = max(ans3, ob[1][i].first + tmp);
        }
        ft2.add(ob[1][i].second, ob[1][i].first);
    }
    cout << max(ans1, max(ans2, ans3)) << endl;
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