#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), ch(n + 1);
    ll sum = 0, add = 0, sub = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += abs(a[i] - i);
        ch[(a[i] - i + n) % n]++;
        if (i == n) break;
        if (a[i] > i)
            sub++;
        else
            add++;
    }
    ll res = sum, ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        sum += add - sub;
        int last = a[n - i + 1];
        sum += abs(last - 1) - abs(last - n);
        add += ch[i] - 1;
        sub = n - 1 - add;
        if (sum < res) {
            res = sum;
            ans = i;
        }
    }
    cout << res << " " << ans << endl;
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