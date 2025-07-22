#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN * 2 + 5];
int f[MAXN * 2 + 5][MAXN * 2 + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++) scanf("%d", &A[i]);

    vector<pii> vec;
    for (int i = 1, j = 1; i <= n * 2; i++) {
        if (i == n * 2 || A[i + 1] > A[j]) {
            vec.push_back({j, i});
            j = i + 1;
        }
    }

    int m = vec.size();
    for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) f[i][j] = -1;
    f[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        int len = vec[i - 1].second - vec[i - 1].first + 1;
        for (int j = 0; j <= n; j++) {
            if (f[i - 1][j] >= 0) f[i][j] = j;
            if (j >= len && f[i - 1][j - len] >= 0) f[i][j] = j - len;
        }
    }

    if (f[m][n] >= 0) {
        vector<int> v1, v2;
        for (int i = m, j = n; i > 0; j = f[i][j], i--) {
            auto &v = (j == f[i][j] ? v1 : v2);
            for (int idx = vec[i - 1].second; idx >= vec[i - 1].first; idx--) v.push_back(A[idx]);
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        for (int i = 1; i <= n; i++) printf("%d%c", v1[i - 1], "\n "[i < n]);
        for (int i = 1; i <= n; i++) printf("%d%c", v2[i - 1], "\n "[i < n]);
    } else {
        printf("-1\n");
    }
    return 0;
}
