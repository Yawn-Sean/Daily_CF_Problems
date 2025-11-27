#include <bits/stdc++.h>

using namespace std;

int query(int i, int j) {
    int res;
    printf("? %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int idx1 = 1;
    vector<int> vis(n + 1, 0);
    vis[idx1] = 1;
    for (int i = 2; i <= n; i++) if (vis[i] == 0) {
        idx1 = query(idx1, i);
        vis[idx1] = 1;
    }
    set<int> s;
    for (int i = 1; i <= n; i++) if (i != idx1) {
        s.insert(i);
    }
    vector<int> ans;
    while (!s.empty()) {
        set<int> ns;
        auto cur = s.begin();
        int x = *cur;
        for (cur++; cur != s.end(); cur++) {
            int idx = query(x, *cur);
            if (idx == idx1) {
                ns.insert(*cur);
            } else {
                x = idx;
            }
        }
        ans.push_back(x);
        s.swap(ns);
    }
    printf("! %llu", ans.size());
    for (auto& x : ans) {
        printf(" %d", x);
    }
    return 0;
}

