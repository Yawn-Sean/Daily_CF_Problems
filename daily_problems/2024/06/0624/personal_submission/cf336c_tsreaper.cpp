#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 30
using namespace std;

int n, A[MAXN + 10];

int lb(int x) { return x & (-x); }

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int p = MAXP - 1; p >= 0; p--) {
        bool flag = false;
        int now = (1 << MAXP) - 1;
        vector<int> vec;
        for (int i = 1; i <= n; i++) if (A[i] >> p & 1) {
            flag = true;
            now &= A[i];
            vec.push_back(A[i]);
        }
        if (flag && lb(now) == (1 << p)) {
            printf("%d\n", vec.size());
            for (int x : vec) printf("%d ", x);
            printf("\n");
            return 0;
        }
    }
    return 0;
}
