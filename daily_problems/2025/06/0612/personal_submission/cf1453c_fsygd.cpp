#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
int ans[10], left[10], right[10], bottom[10], top[10];
char digits[2010][2010];

void solve() {
    for (int i = 0; i <= 9; ++i) {
        top[i] = n;
        bottom[i] = -1;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x = digits[i][j] - '0';
            top[x] = min(top[x], i);
            bottom[x] = max(bottom[x], i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            left[j] = n;
            right[j] = -1;
        }
        for (int j = 0; j < n; ++j) {
            int x = digits[i][j] - '0';
            left[x] = min(left[x], j);
            right[x] = max(right[x], j);
        }
        for (int j = 0; j <= 9; ++j)
            if (right[j] != -1) {
                ans[j] = max(ans[j], (right[j] - left[j]) * max(i, n - 1 - i));
                ans[j] = max(ans[j], max(n - 1 - left[j], right[j]) * max(i - top[j], bottom[j] - i));
            }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", digits[i]);
        for (int i = 0; i <= 9; ++i) ans[i] = 0;
        solve();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(digits[i][j], digits[j][i]);
        solve();
        for (int i = 0; i < 9; ++i) printf("%d ", ans[i]);
        printf("%d\n", ans[9]);
    }
    return 0;
}