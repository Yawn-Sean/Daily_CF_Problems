#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; scanf("%d%d", &a, &b);
    if (~a & b) { printf("-1\n"); return; }

    if (__builtin_popcount(a) == 1) {
        if (a == b) printf("2\n0 %d\n", a);
        else printf("-1\n");
        return;
    }

    vector<int> ans;
    for (int x = a; x; x = (x - 1) & a) if (x != b) ans.push_back(x);
    ans.push_back(0);
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
