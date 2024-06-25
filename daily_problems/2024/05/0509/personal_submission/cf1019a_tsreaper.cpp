#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
typedef pair<int, int> pii;

int n, m;
pii A[MAXN + 10];
long long ans;

vector<pii> vec[MAXN + 10];
bool used[MAXN + 10];

long long gao(int lim) {
    memset(used, 0, sizeof(bool) * (n + 3));
    int has = vec[1].size();
    for (pii p : vec[1]) used[p.second] = true;
    long long ret = 0;
    for (int i = 2; i <= m; i++) if (vec[i].size() >= lim) {
        int det = vec[i].size() - (lim - 1);
        has += det;
        for (int j = 0; j < det; j++) {
            ret += vec[i][j].first;
            used[vec[i][j].second] = true;
        }
    }
    for (int i = 1; i <= n && has < lim; i++) if (!used[i]) has++, ret += A[i].first;
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].second, &A[i].first);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) vec[A[i].second].push_back(pii(A[i].first, i));

    ans = 1e18;
    for (int i = 1; i <= n; i++) ans = min(ans, gao(i));
    printf("%lld\n", ans);
    return 0;
}
