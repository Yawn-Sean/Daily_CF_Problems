#include <bits/stdc++.h>
#define MAXN 9
using namespace std;

int n, A[MAXN + 5][MAXN + 5];

int B[MAXN + 5][MAXN + 5], bel[MAXN + 5];
int C[MAXN + 5][MAXN + 5], cnt[MAXN + 5], mp[MAXN + 5];
char MAP[3][MAXN * 3 + 5][MAXN * 3 + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &A[i][j]);

    for (int S = 1; S <= n; S++) {
        queue<int> q;
        q.push(S); B[S][S] = 1;
        while (!q.empty()) {
            int sn = q.front(); q.pop();
            for (int fn = 1; fn <= n; fn++) if (A[sn][fn]) {
                if (B[S][fn]) continue;
                q.push(fn); B[S][fn] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (B[i][j] && B[j][i]) { bel[i] = j; break; }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (B[i][j] && bel[i] != bel[j]) {
        if (C[bel[i]][bel[j]]) continue;
        C[bel[i]][bel[j]] = 1;
        cnt[bel[i]]++;
    }
    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return cnt[x] > cnt[y];
    });
    for (int i = 0; i < n; i++) mp[ord[i]] = i;

    printf("%d %d %d\n", n * 3, n * 3, n * 3 + 1);
    for (int h = 0; h < n; h++) {
        for (int i = 0; i < n * 3; i++) for (int j = 0; j < n * 3; j++) for (int k = 0; k < 3; k++) MAP[k][i][j] = '.';
        
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
            MAP[2][h * 3 + i][h * 3 + j] = '#';
        for (int i = 1, idx = 0; i <= n; i++) if (bel[i] == ord[h]) {
            MAP[1][h * 3 + idx / 3][h * 3 + idx % 3] = i + '0';
            idx++;
        }

        for (int j = h * 3 + 3; j < n * 3; j++) MAP[2][h * 3 + 1][j] = '#';
        for (int i = 1; i <= n; i++) if (C[ord[h]][i]) {
            int t = mp[i];
            for (int i = h * 3 + 2; i < t * 3; i++) {
                for (int k = 0; k < 2; k++) MAP[k][i][t * 3] = MAP[k][i][t * 3 + 2] = '#';
                MAP[2][i][t * 3 + 1] = '#';
            }
        }

        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < n * 3; i++) {
                for (int j = 0; j < n * 3; j++) printf("%c", MAP[k][i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n * 3; j++) printf(".");
        printf("\n");
    }
    return 0;
}
