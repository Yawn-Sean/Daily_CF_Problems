#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, long long> pil;

int n, A[MAXN + 10], ans[MAXN + 10];

vector<int> e[MAXN + 10], v[MAXN + 10];
vector<pil> stk;
int B[MAXN + 10];

void dfs1(int sn, long long d) {
    stk.push_back({sn, d});
    int head = 0, tail = stk.size() - 1;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (d - stk[mid].second <= A[sn]) tail = mid;
        else head = mid + 1;
    }
    if (head > 0) B[stk[head - 1].first]--;
    if (stk.size() > 1) B[stk[stk.size() - 2].first]++;

    for (int i = 0; i < e[sn].size(); i++) dfs1(e[sn][i], d + v[sn][i]);
    stk.pop_back();
}

int dfs2(int sn) {
    ans[sn] = B[sn];
    for (int fn : e[sn]) ans[sn] += dfs2(fn);
    return ans[sn];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(i + 1); v[x].push_back(y);
    }

    dfs1(1, 0); dfs2(1);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
