#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
string ans1, ans2;

string s_mul(int x, string a) {
    if (x == 0) return "0";
    else if (x > 0) return "(" + to_string(x) + "*" + a + ")";
    else return "(0-" + s_mul(-x, a) + ")";
}

string s_abs(int x) {
    if (x >= 0) return "abs((t-" + to_string(x) + "))";
    else return "abs((t+" + to_string(-x) + "))";
}

string gao(int idx, int t) {
    return s_mul(t / 2, "((1+" + s_abs(idx - 1) + ")-" + s_abs(idx) + ")");
}

void dfs(int *X, int idx, int now, string &ans) {
    if (idx > n) return;
    for (int d = -1; d <= 1; d++) if ((X[idx] + d) % 2 == 0) {
        int t = (X[idx] + d) - now;
        if (ans.size() > 0) ans = "(" + ans + "+" + gao(idx, t) + ")";
        else ans = gao(idx, t);
        dfs(X, idx + 1, now + t, ans);
        return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%*d", &X[i], &Y[i]);
    dfs(X, 1, 0, ans1);
    dfs(Y, 1, 0, ans2);
    printf("%s\n%s\n", ans1.c_str(), ans2.c_str());
    return 0;
}
