#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30;

int n, nxt[N], hd[N];
vector<string> ans;

int dfs(int u, string s) {
    if (u == 26) {
        ans.push_back(s);
        return 1;
    }
    if (nxt[u] == -1) return 0;
    int t = nxt[u]; nxt[u] = -1;
    return dfs(t, s += 'a' + u);
}

void yrlpSolve() {
    cin >> n;
    vector<string> v(n);
    memset(nxt, -1, sizeof nxt);
    for (auto &x : v) cin >> x;
    for (auto &s : v) {
        for (int i = 0; i < s.size() - 1; i++) {
            int a = s[i] - 'a', b = s[i + 1] - 'a';
            if (nxt[a] != -1 && nxt[a] != b) { // 建链同时判断有无一分多的链
                cout << "NO" << endl;
                return;
            }
            nxt[a] = b; hd[b] = 1;
        }
    }
    for (auto s : v) {
        if (nxt[s.back() - 'a'] == -1) {
            nxt[s.back() - 'a'] = 26;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (hd[i] == 0 && nxt[i] != -1) {
            if (!dfs(i, "")) { // 统计链同时判断有无多合一的链
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (accumulate(nxt, nxt + N, 0) != -N) { // 判断有无环
        cout << "NO" << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    for (auto s : ans) cout << s;
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
