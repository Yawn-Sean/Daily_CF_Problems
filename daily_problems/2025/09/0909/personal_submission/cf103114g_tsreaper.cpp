#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, pos[MAXN + 5], ans[MAXN + 5];

vector<int> query(vector<int> &vec) {
    printf("%d", vec.size());
    for (int x : vec) printf(" %d", x);
    printf("\n"); fflush(stdout);

    vector<int> ret;
    for (int i = 1; i <= vec.size(); i++) {
        int x; scanf("%d", &x);
        ret.push_back(x);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    if (n == 1) { printf("! 1\n"); fflush(stdout); return 0; }

    int MAXP = __lg(n - 1);
    for (int p = 0; p <= MAXP; p++) {
        vector<int> vec;
        for (int i = 0; i < n; i++) if (i >> p & 1) vec.push_back(i + 1);
        auto res = query(vec);
        for (int x : res) pos[x] |= 1 << p;
    }
    for (int i = 1; i <= n; i++) ans[pos[i]] = i;
    printf("!");
    for (int i = 0; i < n; i++) printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
    return 0;
}
