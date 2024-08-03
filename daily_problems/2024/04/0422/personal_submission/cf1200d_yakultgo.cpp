#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;

int a[N][N], b[N][N], x[N][N], y[N][N], ans = 0, tot = 0;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = b[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = a[i - 1][j] + (c == 'B');
            b[i][j] = b[i][j - 1] + (c == 'B');
        }
    for (int i = 1; i <= n; i++) {
        tot += a[n][i] == 0;
        tot += b[i][n] == 0;  
    }
    for (int i = k; i <= n; i++)
        for (int j = 1; j <= n; j++)
            x[i][j] = x[i][j - 1] + (a[i - k][j] == 0 && a[n][j] - a[i][j] == 0 && a[i][j] - a[i - k][j] > 0);
    for (int j = k; j <= n; j++)
        for (int i = 1; i <= n; i++)
            y[i][j] = y[i - 1][j] + (b[i][j - k] == 0 && b[i][n] - b[i][j] == 0 && b[i][j] - b[i][j - k] > 0);
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            ans = max(ans, x[i][j] - x[i][j - k] + y[i][j] - y[i - k][j]);
    cout << tot + ans << endl;

    return 0;
}