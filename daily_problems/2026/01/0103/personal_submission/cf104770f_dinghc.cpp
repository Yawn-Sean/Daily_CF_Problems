#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ranges::sort(a);
    vector<int> cnt(n, 0);
    cnt[0] = 1;
    for (int i = 1, j = 0; i < n; i++) {
        if (a[i] != a[i - 1]) {
            j = i;
        }
        cnt[j] += 1;
    }
    int cur = 0;
    vector<vector<int>> vals(n);
    for (int i = 0; i < n; i++) if (cnt[i]) {
        cur += 1;
        cnt[i] -= 1;
        vals[i].push_back(a[i]);
    }
    if (2 * cur - 1 != n) {
        printf("-1\n");
        return 0;
    }
    while (cur > 1) {
        vector<int> p1, p2;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                if (!vals[i].empty()) p1.push_back(i);
            } else {
                p2.push_back(i);
            }
        }
        if (p1.size() != p2.size()) {
            printf("-1\n");
            return 0;
        }
        int m = p1.size();
        for (int j = 0; j < m; j++) {
            int x = p2[j], y = p1[j];
            if (y < x) {
                printf("-1\n");
                return 0;
            }
            cnt[x] -= 1;
            copy(vals[y].begin(), vals[y].end(), back_inserter(vals[x]));
            vals[y].clear();
        }
        cur = (cur + 1) / 2;
    }
    for (auto& v : vals[0]) {
        printf("%d ", v);
    }
    return 0;
}

