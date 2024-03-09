#include <bits/stdc++.h>
#define MAXN ((int) 15e4)
#define MAXS ((int) 1e5)
using namespace std;

int n, A[MAXN + 10][2];

bool flag[MAXS + 10];
vector<int> prime;

bool check(int x) {
    for (int i = 2; i <= n; i++) if (A[i][0] % x > 0 && A[i][1] % x > 0) return false;
    return true;
}

bool gao(int x) {
    for (int p : prime) {
        if (p > x) break;
        if (x % p == 0) {
            if (check(p)) { printf("%d\n", p); return true; }
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1 && check(x)) { printf("%d\n", x); return true; }
    return false;
}

int main() {
    for (int i = 2; i * i <= MAXS; i++) if (!flag[i]) for (int j = i * 2; j <= MAXS; j += i) flag[j] = true;
    for (int i = 2; i <= MAXS; i++) if (!flag[i]) prime.push_back(i);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][0], &A[i][1]);
    if (gao(A[1][0]) || gao(A[1][1])) {}
    else printf("-1\n");
    return 0;
}
