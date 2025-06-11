#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
using ll = long long;

vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

/*
    注意看a、b、c三者满不满足条件只需要看a和b并且b和c是否满足就行
*/
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    auto z = z_function(s);
    vector<int> diff(n + 2);
    int len = s.size();
    for (int i = 1; i < m; i++) {
        if (a[i] - a[i - 1] >= len) continue;
        if (z[a[i] - a[i - 1]] >= a[i - 1] + len - a[i]) continue;
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        diff[a[i]]++;
        diff[a[i] + len]--;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (diff[i] == 0)
            cnt++;
    }
    Z ans = power(Z(26), cnt);
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