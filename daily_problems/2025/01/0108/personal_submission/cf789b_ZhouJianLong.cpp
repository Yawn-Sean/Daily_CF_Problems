#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for(int i = start; i <= end; ++i)
#define erp(i, end, start) for(int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

void solve() {
    i64 b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set<int> st;
    bool ok0 = false, ok1 = false, zero = false;
    rep(i, 1, m) {
        int x;
        cin >> x;
        st.insert(x);
        ok0 |= x == b1;
        ok1 |= x == -b1;
        zero |= x == 0;
    }
    if(llabs(b1) > l) {
        cout << 0 << endl;
        return;
    }
    if(!b1) {
        cout << (zero ? "0" : "inf") << endl;
        return;
    }
    if(!q) {
        cout << (zero ? to_string(!ok0) : "inf") << endl;
        return;
    }
    if(q == 1) {
        cout << (ok0 ? "0" : "inf") << endl;
        return;
    }
    if(q == -1) {
        cout << (ok0 && ok1 ? "0" : "inf") << endl;
        return;
    }
    int cnt = 0;
    while(llabs(b1) <= l) {
        cnt += !st.count(b1);
        b1 *= q;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
