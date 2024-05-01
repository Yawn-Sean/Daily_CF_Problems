#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
using namespace std;

int n, m, A[MAXN + 10], OP[MAXM + 10][2];

int B[MAXN + 10];
bool flag[MAXM + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%d%d", &OP[i][1], &OP[i][0]);

    int mx = 0;
    for (int i = m; i > 0; i--) if (OP[i][0] > mx) {
        flag[i] = true;
        mx = OP[i][0];
    }

    for (int i = 1; i <= m; i++) if (flag[i]) {
        if (OP[i][0] == mx) B[1] = (OP[i][1] == 1 ? 1 : -mx);
        else {
            if (B[1] > 0 && OP[i][1] == 2) {
                int L = B[1], R = L + OP[i][0] - 1;
                B[OP[i][0] + 1] = R + 1;
                B[1] = -R;
            } else if (B[1] < 0 && OP[i][1] == 1) {
                int L = -B[1], R = L - OP[i][0] + 1;
                B[OP[i][0] + 1] = -R + 1;
                B[1] = R;
            }
        }
    }

    vector<int> vec;
    for (int i = 1; i <= mx; i++) vec.push_back(A[i]);
    sort(vec.begin(), vec.end());
    for (int i = 1, j = 1, now; i <= mx; i++) {
        if (B[i] != 0) now = abs(B[i]), j = i;
        A[i] = vec[now - 1];
        if (B[j] > 0) now++;
        else now--;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
