#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string str[205];
int ans[205];
int calc(int idx) {
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < (1 << i); j++) {
            string s;
            for (int k = 0; k < i; k++) {
                if (j & (1 << k)) {
                    s += '1';
                } else {
                    s += '0';
                }
            }
            if (str[idx].find(s) == string::npos) {
                return i - 1;
            }
        }
    }
    return 9;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }
    int m;
    cin >> m;
    for (int i = n + 1; i <= n + m; i++) {
        int l, r;
        cin >> l >> r;
        str[i] = str[l] + str[r];
        ans[i] = max({ans[l], ans[r], calc(i)});
        if (str[i].size() > 1800) {
            str[i] = str[i].substr(0, 900) + str[i].substr(str[i].size() - 900);
        }
    }
    for (int i = n + 1; i <= n + m; i++) {
        cout << ans[i] << endl;
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