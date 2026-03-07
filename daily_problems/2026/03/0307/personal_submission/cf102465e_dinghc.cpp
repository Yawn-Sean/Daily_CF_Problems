#include <bits/stdc++.h>

using namespace std;
constexpr int N = 10000;
char s[N][21];
int p[N];

int main() {
    int n;
    scanf("%d", &n);
    vector<double> mn(n), mx(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s[i], &p[i]);
        mn[i] = max(0.0, p[i] - 0.50);
        mx[i] = min(100.0, p[i] + 0.49);
    }
    double sum_mn = reduce(mn.begin(), mn.end(), 0.0);
    double sum_mx = reduce(mx.begin(), mx.end(), 0.0);
    if (sum_mn > 100.0 || sum_mx < 100.0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        double cur_mx = min(mx[i], 100.0 - sum_mn + mn[i]);
        double cur_mn = max(mn[i], mx[i] - (sum_mx - 100.0));
        printf("%s %.2f %.2f\n", s[i], cur_mn, cur_mx);
    }
    return 0;
}

