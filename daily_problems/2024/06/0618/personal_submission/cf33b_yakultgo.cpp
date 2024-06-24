#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m;
    cin >> m;
    vector<vector<int>> trans(26, vector<int>(26, 1e9));
    for (int i = 0; i < 26; i++) trans[i][i] = 0;
    while (m--) {
        char a, b;
        int x;
        cin >> a >> b >> x;
        trans[a - 'a'][b - 'a'] = min(trans[a - 'a'][b - 'a'], x);
    }

    // 使用floyd
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
            }
        }
    }
    if (s1.size() != s2.size()) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            // 26个字母中找到最小的转换次数
            int cost = INT_MAX, idx = -1;
            for (int j = 0; j < 26; j++) {
                if (trans[s1[i] - 'a'][j] + trans[s2[i] - 'a'][j] < cost) {
                    cost = trans[s1[i] - 'a'][j] + trans[s2[i] - 'a'][j];
                    idx = j;
                }
            }
            if (cost >= 1e9) {
                cout << -1 << endl;
                return;
            }
            ans += cost;
            s1[i] = s2[i] = idx + 'a';
        }
    }
    cout << ans << endl;
    cout << s1 << endl;
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