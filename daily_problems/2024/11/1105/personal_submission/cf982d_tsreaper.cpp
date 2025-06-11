#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, ans1, ans2;

int root[MAXN + 10], sz[MAXN + 10];
multiset<int> ms;

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    ms.erase(ms.find(sz[x])); ms.erase(ms.find(sz[y]));
    root[y] = x; sz[x] += sz[y];
    ms.insert(sz[x]);
}

int main() {
    scanf("%d", &n);

    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec.push_back({x + 1, i});
    }
    sort(vec.begin(), vec.end());

    for (pii p : vec) {
        int idx = p.second;
        root[idx] = idx; sz[idx] = 1; ms.insert(1);
        if (idx - 1 > 0 && sz[idx - 1]) merge(idx, idx - 1);
        if (idx + 1 <= n && sz[idx + 1]) merge(idx, idx + 1);
        if (*(ms.begin()) == *prev(ms.end()) && ans2 < ms.size()) {
            ans1 = p.first;
            ans2 = ms.size();
        }
    }
    printf("%d\n", ans1);
    return 0;
}
