#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, P, X, Y; scanf("%d%d%d%d%d", &n, &m, &P, &X, &Y);
    int a = 0, b = 0;
    for (int i = 1; i <= m; i++) {
        int v; scanf("%d", &v);
        a += v;
        if (v >= Y) b++;
        else b--;
    }
    a += Y * (n - m); b += n - m;
    if (b <= 0) { printf("-1\n"); return 0; }
    vector<int> ans;
    for (int i = 1; i <= n - m; i++) ans.push_back(Y);
    for (int i = 0; i < ans.size() && b > 1; i++) {
        ans[i] = 1;
        a -= Y - 1;
        b -= 2;
    }
    if (a > X) { printf("-1\n"); return 0; }
    for (int v : ans) printf("%d ", v);
    printf("\n");
    return 0;
}
