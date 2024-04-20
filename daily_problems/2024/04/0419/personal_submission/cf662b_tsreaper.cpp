#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 1e5)
using namespace std;

int n, m, A[MAXM + 10][3];

int root[MAXN * 2 + 10];
vector<int> vec[MAXN * 2 + 10][2];
bool ban[MAXN * 2 + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x != y) root[x] = y;
}

vector<int> gao(int X) {
    for (int i = 1; i <= n * 2; i++) root[i] = i;
    for (int i = 1; i <= m; i++) {
        if (A[i][2] == X) {
            merge(A[i][0], A[i][1] + n);
            merge(A[i][0] + n, A[i][1]);
        } else {
            merge(A[i][0], A[i][1]);
            merge(A[i][0] + n, A[i][1] + n);
        }
    }
    for (int i = 1; i <= n; i++) if (findroot(i) == findroot(i + n)) {
        vector<int> ret(n + 1, 0);
        return ret;
    }

    for (int i = 1; i <= n * 2; i++) for (int j = 0; j < 2; j++) vec[i][j].clear();
    for (int i = 1; i <= n; i++) vec[findroot(i)][0].push_back(i);
    for (int i = n + 1; i <= n * 2; i++) vec[findroot(i)][1].push_back(i - n);
    
    vector<int> ret;
    memset(ban, 0, sizeof(bool) * (n * 2 + 3));
    for (int i = 1; i <= n * 2; i++) {
        int r = findroot(i);
        if (ban[r]) continue;
        ban[r] = ban[findroot(i + n)] = true;
        if (vec[r][0].size() < vec[r][1].size()) for (int x : vec[r][0]) ret.push_back(x);
        else for (int x : vec[r][1]) ret.push_back(x);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        char s[3]; scanf("%s", s);
        A[i][2] = (s[0] == 'B' ? 0 : 1);
    }

    vector<int> ansB = gao(0), ansR = gao(1);
    vector<int> ans = (ansB.size() < ansR.size() ? ansB : ansR);
    if (ans.size() > n) { printf("-1\n"); return 0; }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
    return 0;
}
