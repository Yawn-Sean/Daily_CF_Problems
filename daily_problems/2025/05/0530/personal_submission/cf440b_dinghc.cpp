#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    scanf("%d", &n);
    int64 tot = 0;
    vector<int64> a(n);
    for (auto& x : a) {
        scanf("%I64d", &x);
        tot += x;
    }
    int64 v = tot / n;
    int64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int64 d = v - a[i];
        a[i + 1] -= d;
        ans += abs(d);
    }
    printf("%I64d\n", ans);
    return 0;
}

