/*
    对于超过a、b的订单可以取min
    每次询问回答一段区间的v1和+一段区间的v2和
    在线询问，不能每次暴力更新前缀和
    于是用两个树状数组维护
*/
#include <bits/stdc++.h>
using namespace std;

template <class T> struct BIT {
    int n;
    vector<T> w;
    BIT(int n) : n(n), w(n + 1){};
    void add(int x, T v) {
        for (; x <= n; x += x & -x) {
            w[x] += v;
        }
    }
    T ask(int x) {
        T ans = 0;
        for (; x; x -= x & -x) {
            ans += w[x];
        }
        return ans;
    }
    T ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};

void solve(){
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    BIT<int> t1(n), t2(n);
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            t1.add(p, min(b - t1.ask(p, p), x));
            t2.add(p, min(a - t2.ask(p, p), x));
        } else {
            int ans = 0;
            int p;
            cin >> p;
            ans += t1.ask(1, p - 1);
            if (p + k <= n) ans += t2.ask(p + k, n);
            cout << ans << "\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
