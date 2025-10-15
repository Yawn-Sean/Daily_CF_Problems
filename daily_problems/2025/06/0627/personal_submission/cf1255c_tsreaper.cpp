#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans[MAXN + 5];

int cnt[MAXN + 5];
unordered_map<int, unordered_map<int, vector<int>>> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 2; i++) {
        int t[3];
        for (int j = 0; j < 3; j++) scanf("%d", &t[j]), cnt[t[j]]++;
        sort(t, t + 3);

        vector<int> ord = {0, 1, 2};
        for (int j = 0; j < 6; j++) {
            mp[t[ord[0]]][t[ord[1]]].push_back(t[ord[2]]);
            next_permutation(ord.begin(), ord.end());
        }
    }

    for (int i = 1; i <= n; i++) if (cnt[i] == 1) ans[1] = i;
    for (auto &p : mp[ans[1]]) if (cnt[p.first] == 2) ans[2] = p.first;
    for (int i = 3; i <= n; i++) {
        auto &vec = mp[ans[i - 2]][ans[i - 1]];
        for (int x : vec) if (x != ans[i - 3]) ans[i] = x;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
