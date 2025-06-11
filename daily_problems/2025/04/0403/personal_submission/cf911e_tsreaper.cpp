#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, A[MAXN + 5];
vector<int> ans;

bool vis[MAXN + 5], inS[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &A[i]);
        ans.push_back(A[i]);
        vis[A[i]] = true;
    }

    stack<int> stk;
    bool flag = false;
    vector<int> tmp;
    for (int i = 1, j = 1; i <= n; i++) {
        if (vis[i]) {
            while (j <= m && !inS[i]) {
                stk.push(A[j]);
                inS[A[j]] = true;
                j++;
            }
            if (stk.top() != i) { printf("-1\n"); return 0; }
            stk.pop();
            inS[i] = false;
            flag = true;
        } else {
            while (j <= m) {
                stk.push(A[j]);
                inS[A[j]] = true;
                j++;
            }
            if (flag) {
                while (!tmp.empty()) ans.push_back(tmp.back()), tmp.pop_back();
                flag = false;
            }
            tmp.push_back(i);
        }
    }
    while (!tmp.empty()) ans.push_back(tmp.back()), tmp.pop_back();

    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
