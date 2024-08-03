#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

bool flag[MAXN + 10];

int main() {
    int n; scanf("%d", &n);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mp[l].push_back(i);
        mp[r + 1].push_back(-i);
    }

    unordered_set<int> st;
    for (auto &p : mp) {
        auto &vec = p.second;
        for (int x : vec) {
            if (x < 0) st.erase(-x);
            else st.insert(x);
        }
        if (st.size() == 1) flag[*(st.begin())] = true;
    }

    for (int i = 1; i <= n; i++) if (!flag[i]) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
