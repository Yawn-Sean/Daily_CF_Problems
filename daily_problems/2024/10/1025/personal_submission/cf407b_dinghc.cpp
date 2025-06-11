#include <bits/stdc++.h>

using namespace std;
constexpr int M = 1'000'000'007;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (auto& x : p) {
        scanf("%d", &x);
        x -= 1;
    }
    vector<int> s(n + 1);
    vector<int> dp(n);
    dp[0] = 2;
    s[0] = 0;
    for (int i = 1; i < n; i++) {
        s[i] = (s[i - 1] + dp[i - 1]) % M;
        dp[i] = (s[i] + M - s[p[i]] + 2) % M;
    }
    printf("%d\n", (s[n - 1] + dp[n - 1]) % M);
    return 0;
}

