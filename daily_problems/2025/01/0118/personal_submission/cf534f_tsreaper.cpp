#include <bits/stdc++.h>
#define MAXN 5
#define MAXM 20
#define MAGIC 161051
using namespace std;

int n, m, A[MAXN], B[MAXM], ans[MAXM];

vector<int> vec[(MAXN + 1) / 2 + 1];
bitset<32> vis[MAXM][MAGIC];

int idx(array<int, 5> &arr) {
    int ret = 0;
    for (int i = 0; i < n; i++) ret = ret * 11 + arr[i];
    return ret;
}

bool dfs(int pos, array<int, 5> now, int last) {
    if (pos >= m) {
        for (int i = 0; i < n; i++) if (A[i] != now[i]) return false;
        return true;
    }

    auto &bs = vis[pos][idx(now)];
    if (bs[last]) return false;
    bs[last] = true;
    for (int i = 0; i < 5; i++) {
        if (now[i] > A[i]) return false;
        int rem = m - pos;
        if (last >> i & 1) rem--;
        if (now[i] + (rem + 1) / 2 < A[i]) return false;
    }

    for (int msk : vec[B[pos]]) {
        ans[pos] = msk;
        auto nxt = now;
        for (int i = 0; i < 5; i++) if ((last >> i & 1) == 0 && (msk >> i & 1) == 1) nxt[i]++;
        if (dfs(pos + 1, nxt, msk)) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    for (int i = 0; i < (1 << n); i++) {
        vector<int> tmp = {0};
        for (int j = 0; j < n; j++) tmp.push_back(i >> j & 1);
        int cnt = 0;
        for (int j = 1; j <= n; j++) if (tmp[j] == 1 && tmp[j - 1] == 0) cnt++;
        vec[cnt].push_back(i);
    }

    dfs(0, {0, 0, 0, 0, 0}, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[j] >> i & 1) printf("*");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}
