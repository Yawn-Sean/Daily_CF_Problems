#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
long long ans;

long long calc(int *X) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) vec.push_back(X[i]);
    sort(vec.begin(), vec.end());

    long long ret = 0, sm = 0;
    for (int i = 0; i < n; i++) {
        ret += 1LL * vec[i] * i - sm;
        sm += vec[i];
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &Y[i]);
    ans = (calc(X) + calc(Y)) * 2;

    for (int i = 1; i <= n; i++) {
        int x = X[i] + Y[i];
        int y = X[i] - Y[i];
        X[i] = x; Y[i] = y;
    }
    ans -= calc(X) + calc(Y);

    printf("%lld\n", ans);
    return 0;
}
