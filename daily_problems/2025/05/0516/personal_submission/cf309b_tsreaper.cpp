#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, R, C, ans1, ans2;
string s[MAXN + 5];

int f[MAXN + 5], pa[MAXN + 5];
vector<int> e[MAXN + 5], stk;

void dfs(int sn) {
    if (!stk.empty()) {
        int t = stk.size() - min((int) stk.size(), R);
        if (ans2 - ans1 < stk[t] - sn) ans1 = sn, ans2 = stk[t];
    }
    stk.push_back(sn);
    for (int fn : e[sn]) dfs(fn);
    stk.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> R >> C;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        f[i] = f[i - 1] + s[i].size();
    }

    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && f[j] - f[i - 1] + j - i <= C) j++;
        if (i != j) {
            pa[i] = j;
            e[j].push_back(i);
        }
    }
    for (int i = 1; i <= n + 1; i++) if (pa[i] == 0) dfs(i);
    for (int i = ans1; i < ans2; i = pa[i]) {
        for (int j = i; j < pa[i]; j++) {
            if (j > i) cout << " ";
            cout << s[j];
        }
        cout << "\n";
    }
    return 0;
}
