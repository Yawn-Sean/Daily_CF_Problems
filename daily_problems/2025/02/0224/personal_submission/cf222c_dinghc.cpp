#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100'000;
int a[N], b[N];
vector<int> fa[N], fb[N];

constexpr int A = 10'000'000;
int lpf[A + 1];
int pa[A + 1], pb[A + 1];
vector<int> pr;

int init = [] () -> int {
    for (int i = 2; i <= A; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= A; j++) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int q = a[i];
        while (lpf[q] > 1) {
            int p = lpf[q], pow = 0;
            while (q % p == 0) {
                q /= p;
                pow++;
                fa[i].push_back(p);
            }
            pa[p] += pow;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        int q = b[i];
        while (lpf[q] > 1) {
            int p = lpf[q], pow = 0;
            while (q % p == 0) {
                q /= p;
                pow++;
                fb[i].push_back(p);
            }
            pb[p] += pow;
        }
    }
    for (int i = 0; i <= A; i++) {
        pa[i] = pb[i] = min(pa[i], pb[i]);
    }
    for (int i = 0; i < n; i++) {
        for (auto& p : fa[i]) if (pa[p]) {
            a[i] /= p;
            pa[p] -= 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto& p : fb[i]) if (pb[p]) {
            b[i] /= p;
            pb[p] -= 1;
        }
    }
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}

