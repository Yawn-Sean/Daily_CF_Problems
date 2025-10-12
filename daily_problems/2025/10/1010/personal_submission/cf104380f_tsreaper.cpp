#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L, R; scanf("%d%d%d", &n, &L, &R);
    int t = min(L - 1, n - R);
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (n - i + 1 > t) vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < R - L + 1; i++) ans += vec[i];
    printf("%lld\n", ans);
    return 0;
}
