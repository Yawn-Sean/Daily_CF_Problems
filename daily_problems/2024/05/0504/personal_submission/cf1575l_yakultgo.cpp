#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
int cnt = 0;
struct node {
    int x, y;
    bool operator<(const node &a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
};
node b[N];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i >= a[i])
            b[++cnt] = {i - a[i], a[i]};
    }
    sort(b + 1, b + cnt + 1);
    FenwickTree tr(2e5);
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        int len = tr.query(b[i].y - 1) + 1;
        tr.add(b[i].y, len);
        ans = max(ans, len);
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