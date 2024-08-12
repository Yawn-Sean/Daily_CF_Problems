#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n;
    vector<int> pre(26, -1), nxt(26, -1);
    vector<int> vis(26);
    while (n--) {
        string s;
        cin >> s;
        m = s.size();
        vis[s[0] - 'a'] = 1;
        for (int i = 1; i < m; i++) {
            int u = s[i - 1] - 'a', v = s[i] - 'a';
            if (nxt[u] != -1 && nxt[u] != v || pre[v] != -1 && pre[v] != u) {
                cout << "NO";
                return;
            }
            nxt[u] = v, pre[v] = u, vis[v] = 1;
        }
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        if (vis[i] && pre[i] == -1) {
            for (int j = i; j != -1; j = nxt[j]) {
                vis[j] = 0;
                ans.push_back(j + 'a');
            }
        }
    }

    for (int i = 0; i < 26; i++)
        if (vis[i]) {
            cout << "NO";
            return;
        }

    cout << ans;
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
