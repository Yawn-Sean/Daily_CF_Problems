#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<int> a(n), b(m);
    for (auto& x : a) scanf("%d", &x);
    for (auto& x : b) scanf("%d", &x);
    vector<vector<int>> g(p);
    for (int i = 0; i < n; i++) {
        g[i % p].push_back(a[i]);
    }
    vector<int> ans;
    map<int, int> f2;
    for (auto& x : b) {
        f2[x] += 1;
    }
    int to_match = f2.size();
    for (int r = 0; r < p; r++) {
        auto& v = g[r];
        int k = v.size();
        map<int, int> f1;
        int match_count = 0;
        for (int i = 0, j = 0; i < k; i++) {
            f1[v[i]] += 1;
            if (f2.find(v[i]) != f2.end()) {
                if (f1[v[i]] == f2[v[i]]) match_count += 1;
                else if (f1[v[i]] == f2[v[i]] + 1) match_count -= 1;
            }
            if (i - j + 1 > m) {
                f1[v[j]] -= 1;
                if (f2.find(v[j]) != f2.end()) {
                    if (f1[v[j]] == f2[v[j]]) match_count += 1;
                    else if (f1[v[j]] == f2[v[j]] - 1) match_count -= 1;
                }
                j += 1;
            }
            if (i - j + 1 == m && match_count == to_match) {
                ans.push_back(j * p + r);
            }
        }
    }
    printf("%d\n", ans.size());
    ranges::sort(ans);
    for (auto& x : ans) {
        printf("%d ", x + 1);
    }
    return 0;
}

