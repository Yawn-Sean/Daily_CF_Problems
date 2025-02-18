#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;

char s[N];
int sum[26][N], ret[26][N];

void yrlpSolve() {
    int n, k; scanf("%d%s%d", &n, s + 1, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[j][i] = sum[j][i - 1] + (s[i] == 'a' + j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 0; k < 26; k++) {
                int x = sum[k][j] - sum[k][i - 1];
                ret[k][j - i + 1 - x] = max(ret[k][j - i + 1 - x], j - i + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            ret[j][i] = max(ret[j][i], ret[j][i - 1]);
        }
    }
    for (int i = 0; i < k; i++) {
        int x; char c; cin >> x >> c;
        cout << ret[c - 'a'][x] << endl;
    }
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
