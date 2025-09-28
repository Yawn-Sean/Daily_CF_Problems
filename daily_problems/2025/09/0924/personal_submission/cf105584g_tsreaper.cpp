#include  <bits/stdc++.h>
#define MAXN 70
#define MAXA 150
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5][2];

int from[MAXN + 5][MAXN + 5][MAXN * MAXA * 2 + 5];

void solve() {
    scanf("%d", &n);
    if (n == 0) return;

    int sm = 0, even = 0;
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sm += A[i];
        if (A[i] % 2 == 0) even = i;
        else odd.push_back(i);
    }

    if (sm % 2 != 0) { printf("No\n"); return; }
    if (even == 0) {
        int base = n * MAXA + 2;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = -n * MAXA; k <= n * MAXA; k++)
            from[i][j][k + base] = 0;
        from[0][0][base] = base;
        for (int i = 1; i <= n; i++) for (int j = 0; j <= i; j++) for (int k = -i * MAXA; k <= i * MAXA; k++) {
            if (from[i - 1][j][k + base]) from[i][j][k + base] = -1;
            if (j > 0 && k - A[i] >= -i * MAXA && from[i - 1][j - 1][k - A[i] + base]) from[i][j][k + base] = k - A[i] + base;
        }
        if (from[n][n / 2][sm / 2 + base] == 0) { printf("No\n"); return; }

        vector<int> vec1, vec2;
        for (int i = n, j = n / 2, k = sm / 2 + base; i > 0; i--) {
            int t = from[i][j][k];
            if (t > 0) {
                vec1.push_back(i);
                k = t; j--;
            } else {
                vec2.push_back(i);
            }
        }

        vector<int> ord;
        for (int i = 0; i < vec1.size(); i++) ord.push_back(vec1[i]), ord.push_back(vec2[i]);

        ans[ord[0]][0] = A[ord[0]]; ans[ord[0]][1] = 0;
        for (int i = 1; i < ord.size(); i++) {
            ans[ord[i]][0] = ans[ord[i - 1]][1];
            ans[ord[i]][1] = A[ord[i]] - ans[ord[i]][0];
        }
    } else {
        odd.push_back(even);
        int sz = odd.size();
        for (int i = 0; i < sz; i++) {
            int x = 0;
            for (int j = 0; j < sz; j++)
                x += (j & 1 ? -1 : 1) * A[odd[(i + j) % sz]];
            x /= 2;
            ans[odd[i]][0] = x;
            ans[odd[(i - 1 + sz) % sz]][1] = x;
        }
        for (int i = 1; i <= n; i++) if (A[i] % 2 == 0 && i != even) ans[i][0] = ans[i][1] = A[i] / 2;
    }

    printf("Yes\n");
    for (int j = 0; j < 2; j++) for (int i = 1; i <= n; i++) printf("%d%c", ans[i][j], "\n "[i < n]);
}

int main() {
    while (true) {
        solve();
        if (n == 0) break;
    }
    return 0;
}
