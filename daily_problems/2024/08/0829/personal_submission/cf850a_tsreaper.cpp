#include <bits/stdc++.h>
#define MAXN 32
using namespace std;

int n, A[MAXN + 5][5];
vector<int> ans;

bool check(int i) {
    for (int j = 1; j <= n; j++) if (i != j) for (int k = j + 1; k <= n; k++) if (i != k) {
        int t = 0;
        for (int d = 0; d < 5; d++) t += (A[j][d] - A[i][d]) * (A[k][d] - A[i][d]);
        if (t > 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    if (n > MAXN) { printf("0\n"); return 0; }
    for (int i = 1; i <= n; i++) for (int j = 0; j < 5; j++) scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i++) if (check(i)) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d\n", x);
    return 0;
}
