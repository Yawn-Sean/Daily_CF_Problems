#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<int, int> pii;

int n, X[MAXN + 10], Y[MAXN + 10];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    vector<array<long long, 3>> vec;
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) {
        long long d = 1LL * (X[i] - X[j]) * (X[i] - X[j]) + 1LL * (Y[i] - Y[j]) * (Y[i] - Y[j]);
        long long dx = X[i] - X[j], dy = Y[i] - Y[j];
        if (dx == 0) vec.push_back({d, 0, 0});
        else {
            long long g = gcd(abs(dx), abs(dy));
            if (dx * dy < 0) vec.push_back({d, -abs(dx) / g, abs(dy) / g});
            else vec.push_back({d, abs(dx) / g, abs(dy) / g});
        }
    }

    sort(vec.begin(), vec.end());
    for (int i = 0, cnt = 0; i < vec.size(); i++) {
        cnt++;
        if (i + 1 == vec.size() || vec[i] != vec[i + 1]) {
            ans += 1LL * cnt * (cnt - 1) / 2;
            cnt = 0;
        }
    }
    printf("%lld\n", ans / 2);
    return 0;
}
