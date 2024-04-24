#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    vector<string> c(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        c[i] = str;
        int s = count(str.begin(), str.end(), 's');
        int h = count(str.begin(), str.end(), 'h');
        if (h == 0) {
            cnt += s;
            continue;
        }
        a.push_back({s, h, i});
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return 1ll * a[0] * b[1] > 1ll * b[0] * a[1];
    });
    string str = string(cnt, 's');
    for (int i = 0; i < a.size(); i++) {
        str += c[a[i][2]];
    }
    ll ans = 0;
    int h = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == 'h') {
            h++;
        } else {
            ans += h;
        }
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