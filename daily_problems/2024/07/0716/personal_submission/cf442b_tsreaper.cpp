#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
double P[MAXN + 10];
long double ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &P[i]);
    sort(P + 1, P + n + 1);
    if (P[n] == 1) { printf("1\n"); return 0; }

    for (int len = 1; len <= n; len++) for (int i = 0; i <= len; i++) {
        vector<double> vec;
        for (int j = 1; j <= i; j++) vec.push_back(P[j]);
        for (int j = len - i; j > 0; j--) vec.push_back(P[n + 1 - j]);
        long double prod = 1;
        for (double x : vec) prod *= 1 - x;
        long double t = 0;
        for (double x : vec) t += prod * x / (1 - x);
        ans = max(ans, t);
    }
    printf("%.12Lf\n", ans);
    return 0;
}
