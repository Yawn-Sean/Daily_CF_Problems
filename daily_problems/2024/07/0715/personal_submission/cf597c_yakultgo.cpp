#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
template <typename T>
struct BIT {
    vector<T> tr;
    BIT(int n) : tr(n + 10, 0) {}
    static inline int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, T delta) {  
        while (x < tr.size()) {
            tr[x] += delta;
            x += lowbit(x);
        }
    }
    T query(int x) {
        T res = 0;
        while (x > 0) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }
    T calc(int l, int r) {
        return query(r) - query(l - 1);
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<BIT<ll>> bit(k + 2, BIT<ll>(n));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = k + 1; j >= 2; j--) {
            bit[j].add(x, bit[j - 1].query(x - 1));
        }
        bit[1].add(x, 1);
    }
    cout << bit[k + 1].query(n) << endl;
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