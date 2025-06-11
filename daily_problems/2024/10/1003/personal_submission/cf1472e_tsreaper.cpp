#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN + 10];

void solve() {
    scanf("%d", &n);
    vector<array<int, 3>> vec;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec.push_back({x, -y, i});
        if (x != y) vec.push_back({y, -x, i});
    }
    sort(vec.begin(), vec.end());

    for (int i = 1; i <= n; i++) ans[i] = -1;
    pii mn = {2e9, -1};
    for (auto &arr : vec) {
        int y = -arr[1], idx = arr[2];
        if (mn.first < y) ans[idx] = mn.second;
        if (y < mn.first) mn = {y, idx};
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
