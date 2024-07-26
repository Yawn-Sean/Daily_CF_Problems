#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10], B[MAXN + 10];

int cnt[MAXN + 10];

vector<pii> gao(int *A) {
    vector<pii> ret;
    memset(cnt, 0, sizeof(int) * (n + 3));
    for (int i = 1, j = 1; i <= n; i++) if (i == n || A[i] != A[i + 1]) {
        cnt[A[i]] += i - j + 1;
        ret.push_back({A[i], cnt[A[i]]});
        j = i + 1;
    }
    return ret;
}

bool solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    vector<pii> v1 = gao(A), v2 = gao(B);
    for (int i = v2.size() - 1, j = v1.size() - 1; i >= 0; i--) {
        while (j >= 0 && v1[j].first != v2[i].first) j--;
        if (j < 0 || v1[j].second < v2[i].second) return false;
    }
    return true;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
