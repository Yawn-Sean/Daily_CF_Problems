#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        float t;
        scanf("%d", &s[i]);
        scanf("%f", &t);
    }
    vector<int> dp(n);
    dp[0] = s[0];
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] >= dp[l]) {
            dp[++l] = s[i];
        } else {
            int j = upper_bound(dp.begin(), dp.begin() + l + 1, s[i]) - dp.begin();
            dp[j] = s[i];
        }
    }
    printf("%d\n", n - l - 1);
    return 0;
}

