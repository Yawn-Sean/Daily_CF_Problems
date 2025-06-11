#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, now;
int q[110], q_inv[110], target[110], a[110], tmp[110];

bool check(int *a, int *b, int n) {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
    for (int i = 1; i <= n; ++i) q_inv[q[i]] = i;
    for (int i = 1; i <= n; ++i) scanf("%d", &target[i]);
    
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        if (target[i] != i)
            flag = false;
    if (flag) {
        printf("NO\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) tmp[j] = a[q[j]];
        for (int j = 1; j <= n; ++j) a[j] = tmp[j];
        if (check(a, target, n)) {
            if ((k - i) % 2 == 0 && (i != 1 || k == 1 || !check(q_inv, target, n))) {
                printf("YES\n");
                return 0;
            }
            break;
        }
    }

    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) tmp[j] = a[q_inv[j]];
        for (int j = 1; j <= n; ++j) a[j] = tmp[j];
        if (check(a, target, n)) {
            if ((k - i) % 2 == 0 && (i != 1 || k == 1 || !check(q, target, n))) {
                printf("YES\n");
                return 0;
            }
            break;
        }
    }

    printf("NO\n");

    return 0;
}