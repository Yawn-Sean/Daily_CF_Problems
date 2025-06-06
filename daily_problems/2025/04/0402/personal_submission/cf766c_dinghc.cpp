#include <bits/stdc++.h>
 
using namespace std;
constexpr int M = 1e9 + 7;
constexpr int N = 1'000;
char s[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    array<int, 26> a;
    for (auto& x : a) {
        scanf("%d", &x);
    }
    int mx_l = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> dp2(n + 1, n);
    dp2[0] = 0;
    for (int i = 1; i <= n; i++) {
        int j = i - 1;
        int l = i - a[s[j] - 'a'];
        while (j >= max(0, l)) {
            mx_l = max(mx_l, i - j);
            dp[i] = (dp[i] + dp[j]) % M;
            dp2[i] = min(dp2[i], dp2[j] + 1);
            l = max(l, i - a[s[--j] - 'a']);
        }
    }
    printf("%d\n%d\n%d\n", dp[n], mx_l, dp2[n]);
    return 0;
}

