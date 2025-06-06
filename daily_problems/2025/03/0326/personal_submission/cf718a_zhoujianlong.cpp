#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for (int i = start; i <= end; ++i)
#define erp(i, end, start) for (int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

void solve() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int mid = s.find('.');
    int i = mid + 1;
    while (i < n && s[i] <= '4')
        ++i;
    if (i == n) {
        cout << s << endl;
        return;
    }
    while (i > mid && t && s[i] >= '5') {
        s[i - 1]++;
        --i;
        --t;
        while (s[i] == '9' + 1) {
            s[i - 1]++;
            --i;
        }
    }
    if (i == mid) {
        s = '0' + s;
        s[i]++;
        while (s[i] == '9' + 1) {
            s[i] = '0';
            s[i - 1]++;
            --i;
        }
        int i0 = i != 0;
        cout << s.substr(i0, mid - i0 + 1) << endl;
        return;
    }
    cout << s.substr(0, i + 1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
