#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, A[MAXN + 5], B[MAXN + 5];
long long ans1, ans2;
vector<int> best;

int f[MAXN + 5];

void update(long long tmp1, long long tmp2, vector<int> &now) {
    if (ans1 * tmp2 < ans2 * tmp1) {
        ans1 = tmp1; ans2 = tmp2;
        best = now;
    }
}

int main() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i], &B[i]);
        m = max(m, A[i]);
        mx = max(mx, B[i]);
    }

    ans1 = 0; ans2 = 1;
    vector<pii> vec;
    long long tmp1, tmp2;
    vector<int> now;
    for (int i = 1; i <= mx && i <= m; i++) {
        memset(f, 0, sizeof(int) * (m + 3));
        for (int j = 1; j <= n; j++) f[A[j]] += min(i, B[j]);
        vec.clear();
        for (int j = 1; j <= m; j++) vec.push_back({f[j], j});
        sort(vec.begin(), vec.end(), greater<pii>());

        tmp1 = 0; tmp2 = i;
        now.clear();
        for (int j = 1; j <= i; j++) tmp1 += vec[j - 1].first, now.push_back(vec[j - 1].second);
        update(tmp1, tmp2, now);
    }

    for (int i = mx + 1; i <= m; i++) {
        tmp1 += vec[i - 1].first; tmp2++;
        now.push_back(vec[i - 1].second);
        update(tmp1, tmp2, now);
    }

    printf("%d\n", best.size());
    for (int x : best) printf("%d ", x);
    printf("\n");
    return 0;
}
