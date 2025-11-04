#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;
vector<int> ans[MAXN + 5];

void gao(int l, int r) {
    if (l > r) return;
    printf("? %d", (r - l) * 2 + 1);
    for (int i = l; i < r; i++) printf(" %d %d", i, i);
    printf(" %d\n", r);
    fflush(stdout);

    vector<int> vec;
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int x; scanf("%d", &x);
        vec.push_back(x);
    }
    reverse(vec.begin(), vec.end());

    unordered_set<int> st;
    for (int i = l; i < r; i++) {
        while (st.count(vec.back()) == 0) {
            ans[i].push_back(vec.back());
            st.insert(vec.back());
            vec.pop_back();
        }
        for (int j = 1; j <= st.size(); j++) vec.pop_back();
        st.clear();
    }
    while (!vec.empty()) ans[r].push_back(vec.back()), vec.pop_back();
}

int main() {
    scanf("%d", &n);
    gao(1, n / 2);
    gao(n / 2 + 1, n);

    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %d", ans[i].size());
        for (int x : ans[i]) printf(" %d", x);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}
