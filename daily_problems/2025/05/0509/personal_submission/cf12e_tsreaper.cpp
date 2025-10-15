#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int A[MAXN + 5][MAXN + 5];
bool used[MAXN + 5];

int main() {
    int n; scanf("%d", &n);
    for (int j = 2; j <= n; j++) A[1][j] = A[j][1] = j - 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) used[j] = false;
        for (int j = 1; j < i; j++) used[A[i][j]] = true;
        for (int j = i + 1, now = A[i][i - 1]; j <= n; j++) {
            while (used[now] || now == A[i - 1][j]) {
                now++;
                if (now == n) now = 1;
            }
            A[i][j] = A[j][i] = now;
            used[now] = true;
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) printf("%d%c", A[i][j], "\n "[j < n]);
    return 0;
}
