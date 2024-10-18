#include <bits/stdc++.h>
#define MAXN 150000
using namespace std;

int n;

int root[MAXN + 10];
vector<int> vec[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        vec[i].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x = findroot(x); y = findroot(y);
        assert(x != y);
        if (vec[x].size() < vec[y].size()) swap(x, y);
        root[y] = x;
        for (int t : vec[y]) vec[x].push_back(t);
        vec[y].clear();
    }
    auto &ans = vec[findroot(1)];
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
