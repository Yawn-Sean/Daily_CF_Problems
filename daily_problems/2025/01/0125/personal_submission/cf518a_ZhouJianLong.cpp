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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int j = -1, k = -1;
    rep(i, 0, n - 1) {
        if(s[i] + 1 < t[i] || k != -1) {
            j = i;
            break;
        }
        if(s[i] < t[i]) {
            k = i;
        }
    }
    if(j == -1) {
        cout << "No such string" << endl;
        return;
    }
    string ans = s;
    if(ans[j] != 'z') {
        ans[j]++;
    } else {
        ans[k]++;
        bool ok = false;
        rep(i, k + 1, n - 1) {
            ans[i] = 'a';
            ok |= ans[i] < t[i];
        }
        if(!ok) {
            cout << "No such string" << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
