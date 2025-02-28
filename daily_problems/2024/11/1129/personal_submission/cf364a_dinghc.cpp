#include <bits/stdc++.h>

using namespace std;
constexpr int N = 4000;
char s[N + 1];

int main() {
    int a;
    scanf("%d", &a);
    scanf("%s", s);
    int n = strlen(s);
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + s[i - 1] - '0';
    }
    vector<int> mp(n * 9 + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mp[pre[j] - pre[i]] += 1;
        }
    }
    long long ans = 0;
    if (a == 0) {
        ans = 1LL * mp[0] * ((n + 1) * n / 2 - mp[0]) * 2 + 1LL * mp[0] * mp[0];
    } else {
        for (int i = 1; i <= n * 9; i++) {
            if (a % i == 0 && a / i <= n * 9) {
                ans += 1LL * mp[i] * mp[a / i];
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}

