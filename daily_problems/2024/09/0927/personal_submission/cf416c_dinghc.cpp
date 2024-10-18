#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> reqs(n);
    for (auto&[c, p] : reqs) {
        scanf("%d%d", &c, &p);
    }
    int k;
    scanf("%d", &k);
    set<pair<int, int>> st;
    for (int i = 0, x; i < k; i++) {
        scanf("%d", &x);
        st.emplace(x, i);
    }
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    ranges::sort(indices, [&] (int a, int b) {
        return reqs[a].second > reqs[b].second;
    });
    int cnt = 0;
    int tot = 0;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        auto&[c, p] = reqs[idx];
        auto it = st.lower_bound(make_pair(c, 0));
        if (it != st.end()) {
            ans[idx] = it->second;
            st.erase(it);
            cnt++;
            tot += p;
        }
    }
    printf("%d %d\n", cnt, tot);
    for (int i = 0; i < n; i++) if (ans[i] != -1) {
        printf("%d %d\n", i + 1, ans[i] + 1);
    }
    return 0;
}

