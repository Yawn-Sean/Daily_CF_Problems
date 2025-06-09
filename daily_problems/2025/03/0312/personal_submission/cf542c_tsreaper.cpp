#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int n, A[MAXN + 5];
long long ans;

vector<int> e[MAXN + 5];
bool vis[MAXN + 5];
int dis[MAXN + 5];

vector<int> findCycle(int S) {
    stack<int> stk;
    for (; !vis[S]; S = A[S]) {
        vis[S] = true;
        stk.push(S);
    }

    vector<int> ret;
    while (stk.top() != S) {
        ret.push_back(stk.top());
        stk.pop();
    }
    ret.push_back(S);
    return ret;
}

int dfs(int sn, int d) {
    dis[sn] = d;
    int ret = d;
    for (int fn : e[sn]) if (dis[fn] < 0) ret = max(ret, dfs(fn, d + 1));
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        e[A[i]].push_back(i);
    }

    ans = 1;
    int mx = 0;
    memset(dis, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) if (dis[i] < 0) {
        auto cycle = findCycle(i);
        for (int x : cycle) dis[x] = 0;
        int len = cycle.size(), t = 1;
        for (int x : cycle) t = max(t, dfs(x, 0));
        mx = max(mx, (t + len - 1) / len * len);
        ans = ans / gcd(ans, len) * len;
    }
    ans = (mx + ans - 1) / ans * ans;
    printf("%lld\n", ans);
    return 0;
}
