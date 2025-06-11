#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 5];

vector<int> pos[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        pos[A[i]].push_back(i);
    }

    int base = 0;
    for (int i = 2; i <= n; i++) if (A[i] != A[i - 1]) base++;

    int ans = 0, best = 1e9;
    for (int k = 1; k <= K; k++) {
        int tmp = base;
        for (int i = 0, j = 0; i < pos[k].size(); i++) {
            if (i + 1 == pos[k].size() || pos[k][i] + 1 != pos[k][i + 1]) {
                if (pos[k][j] > 1) tmp--;
                if (pos[k][i] < n) tmp--;
                if (pos[k][j] > 1 && pos[k][i] < n && A[pos[k][j] - 1] != A[pos[k][i] + 1]) tmp++;
                j = i + 1;
            }
        }
        if (tmp < best) best = tmp, ans = k;
    }
    printf("%d\n", ans);
    return 0;
}
