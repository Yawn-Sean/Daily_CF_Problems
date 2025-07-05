#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void gao(int l, int r, int d) {
    if (l == r) return;
    if (ans.size() <= d) ans.push_back({});
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++) ans[d].push_back(i);
    gao(l, mid, d + 1); gao(mid + 1, r, d + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; scanf("%d", &n);
    gao(1, n, 0);
    printf("%d\n", ans.size());
    for (auto &vec : ans) {
        printf("%d", vec.size());
        for (int x : vec) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
