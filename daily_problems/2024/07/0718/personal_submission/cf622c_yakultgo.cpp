#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
/*
    单调栈记录右边第一个不相等的数
*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> stk;
    vector<int> nxt(n, n);
    for (int i = 0; i < n; i++) {
        while (stk.size() && a[stk.top()] != a[i]) {
            nxt[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (a[l] != x) {
            cout << l + 1 << endl;
        } else if (nxt[l] <= r) {
            cout << nxt[l] + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
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