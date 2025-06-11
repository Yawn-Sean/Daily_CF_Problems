#include <bits/stdc++.h>
#define MAXN 50
using namespace std;
typedef pair<int, int> pii;

int n;
char s1[MAXN + 10], s2[MAXN + 10];
vector<pii> ans;

bool gao(int i) {
    for (int j = i + 1; j <= n; j++) if (s1[i] == s1[j]) {
        ans.push_back({j, i});
        swap(s1[j], s2[i]);
        return true;
    }
    for (int j = i + 1; j <= n; j++) if (s1[i] == s2[j]) {
        ans.push_back({j, j});
        ans.push_back({j, i});
        swap(s1[j], s2[j]);
        swap(s1[j], s2[i]);
        return true;
    }
    return false;
}

void solve() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    ans.clear();
    for (int i = 1; i <= n; i++) if (s1[i] != s2[i]) {
        if (!gao(i)) { printf("No\n"); return; }
    }
    printf("Yes\n%d\n", ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
