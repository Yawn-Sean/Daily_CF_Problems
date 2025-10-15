#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> mst(m), edges(m);
    for (auto& [w, f] : mst) {
        scanf("%d%d", &w, &f);
    }
    vector<int> indices(m);
    iota(indices.begin(), indices.end(), 0);
    ranges::sort(indices, [&] (int a, int b) {
        return mst[a].first < mst[b].first || mst[a].first == mst[b].first && mst[a].second > mst[b].second;
    });
    int u = 1, from = 2, to = 3;
    for (int i = 0; i < m; i++) {
        int j = indices[i];
        auto& [_, f] = mst[j];
        if (f == 1) {
            edges[j] = make_pair(++u, 1);
        } else {
            if (from == to) {
                to += 1;
                from = 2;
            }
            if (to > u) {
                printf("-1\n");
                return 0;
            }
            edges[j] = make_pair(from++, to);
        }
    }
    for (auto& [u, v] : edges) {
        printf("%d %d\n", u, v);
    }
    return 0;
}

