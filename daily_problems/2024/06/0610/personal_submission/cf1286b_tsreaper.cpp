#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10], C[MAXN + 10];

bool failed;
vector<int> e[MAXN + 10];
int sz[MAXN + 10];

void dfs2(int sn, vector<pii> &vec) {
    vec.push_back(pii(A[sn], sn));
    for (int fn : e[sn]) dfs2(fn, vec);
}

void dfs(int sn) {
    for (int fn : e[sn]) {
        dfs(fn);
        if (failed) return;
        sz[sn] += sz[fn];
    }
    if (C[sn] > sz[sn]) { failed = true; return; }

    vector<pii> vec;
    for (int fn : e[sn]) dfs2(fn, vec);
    sort(vec.begin(), vec.end());

    int m = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (i == C[sn]) A[sn] = ++m;
        A[vec[i].second] = ++m;
    }
    if (A[sn] == 0) A[sn] = ++m;
    sz[sn]++;
}

int main() {
    scanf("%d", &n);
    int R;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d%d", &x, &C[i]);
        if (x == 0) R = i;
        else e[x].push_back(i);
    }

    dfs(R);
    if (failed) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    }
    return 0;
}
