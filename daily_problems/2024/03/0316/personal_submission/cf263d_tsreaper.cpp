#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, K;
vector<int> ans;

vector<int> e[MAXN + 10];
int dep[MAXN + 10];
stack<int> stk;

bool dfs(int sn, int d) {
    dep[sn] = d;
    stk.push(sn);
    for (int fn : e[sn]) {
        if (dep[fn]) {
            if (dep[sn] - dep[fn] >= K) {
                while (stk.top() != fn) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
                ans.push_back(fn);
                return true;
            }
        } else {
            if (dfs(fn, d + 1)) return true;
        }
    }
    stk.pop();
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) if (!dep[i] && dfs(i, 1)) break;
    assert(ans.size() > K);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
    return 0;
}
