#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXM ((int) 1e6)
#define MAXW ((int) 1e8)
using namespace std;
typedef pair<int, int> pii;

int n, m, A[MAXM + 10];
long long B[MAXM + 10];

struct Edge {
    int sn, fn, nxt;
};
Edge e[MAXM + 10];
int p[MAXN + 10];

stack<int> stk;
int clk, dfn[MAXN + 10], low[MAXN + 10];
bool inS[MAXN + 10];

int bCnt, bel[MAXN + 10];
long long sm[MAXN + 10];

vector<int> E[MAXN + 10], V[MAXN + 10];
long long f[MAXN + 10];

void adde(int sn, int fn, int idx) {
    e[idx] = {sn, fn, p[sn]};
    p[sn] = idx;
}

void tarjan(int sn) {
    dfn[sn] = low[sn] = ++clk;
    stk.push(sn); inS[sn] = true;
    for (int i = p[sn]; i > 0; i = e[i].nxt) {
        int fn = e[i].fn;
        if (!dfn[fn]) {
            tarjan(fn);
            low[sn] = min(low[sn], low[fn]);
        } else if (inS[fn]) {
            low[sn] = min(low[sn], dfn[fn]);
        }
    }

    if (dfn[sn] == low[sn]) {
        bCnt++;
        while (stk.top() != sn) {
            bel[stk.top()] = bCnt;
            inS[stk.top()] = false;
            stk.pop();
        }
        bel[stk.top()] = bCnt;
        inS[stk.top()] = false;
        stk.pop();
    }
}

long long dp(int sn) {
    if (f[sn] >= 0) return f[sn];
    f[sn] = 0;
    for (int i = 0; i < E[sn].size(); i++) {
        int fn = E[sn][i];
        f[sn] = max(f[sn], dp(fn) + V[sn][i]);
    }
    return f[sn] += sm[sn];
}

int main() {
    vector<long long> vec1, vec2;
    vec1.push_back(0); vec2.push_back(0);
    for (int i = 1; ; i++) {
        vec1.push_back(vec1.back() + i);
        if (vec1.back() > MAXW) break;
        vec2.push_back(vec2.back() + vec1.back());
    }

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d%d", &x, &y, &A[i]);
        adde(x, y, i);
        int head = 0, tail = vec1.size() - 1;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (vec1[mid] < A[i]) head = mid;
            else tail = mid - 1;
        }
        B[i] = 1LL * A[i] * (head + 1) - vec2[head];
    }

    int S; scanf("%d", &S);
    tarjan(S);

    for (int i = 1; i <= m; i++) {
        int sn = e[i].sn, fn = e[i].fn;
        if (dfn[sn] == 0 || dfn[fn] == 0) continue;
        if (bel[sn] == bel[fn]) {
            sm[bel[sn]] += B[i];
        } else {
            E[bel[fn]].push_back(bel[sn]);
            V[bel[fn]].push_back(A[i]);
        }
    }

    for (int i = 1; i <= bCnt; i++) f[i] = -1;
    long long ans = 0;
    for (int i = 1; i <= bCnt; i++) ans = max(ans, dp(i));
    printf("%lld\n", ans);
    return 0;
}
