#include "bits/stdc++.h"

using namespace std;

#ifndef ONLINE_JUDGE
#include "test.h"
#include "dbg.h"
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif


#define IOS ios::sync_with_stdio(0),cin.tie(0)

using ll = long long;
using ull = unsigned long long;

#define endl '\n'
#define int ll

using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
const int inf = 1e18;
const int mod = 998244353;

void init() {
}


void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> op(n + 1);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '-')
            cin >> op[i];
    }
    stack<int> s;
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        if (op[i]) {
            if (!s.empty() && op[i] > s.top()) {
                cout << "NO" << endl;
                return;
            }
            s.emplace(op[i]);
        }
        else {
            if (s.empty()) {
                cout << "NO" << endl;
                return;
            }
            ans.emplace_back(s.top());
            s.pop();
        }
    }
    cout << "YES" << endl;
    reverse(ans.begin(), ans.end());
    for(auto i :ans)cout<<i<<" ";
}

signed main() {
    IOS;
    init();
    // debug(1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

// 11 1
//  11 10
//  1 4
//  9 10
//  8 4
//  3 6
//  5 7
//  6 1
//  10 2
//  11 7
//  11 1
