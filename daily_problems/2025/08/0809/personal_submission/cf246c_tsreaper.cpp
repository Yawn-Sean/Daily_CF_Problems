#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, K, A[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    unordered_set<int> st;
    vector<vector<int>> ans = {{0}};
    for (int i = 1; i <= n; i++) {
        int sz = ans.size();
        for (int j = 0; j < sz && ans.size() <= K; j++) {
            int v = ans[j][0] + A[i];
            if (st.count(v)) continue;
            st.insert(v);
            ans.push_back(ans[j]);
            ans.back()[0] += A[i];
            ans.back().push_back(A[i]);
        }
    }

    for (int i = 1; i <= K; i++) {
        printf("%d", ans[i].size() - 1);
        for (int j = 1; j < ans[i].size(); j++) printf(" %d", ans[i][j]);
        printf("\n");
    }
    return 0;
}
