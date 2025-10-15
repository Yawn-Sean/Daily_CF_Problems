#include <bits/stdc++.h>
 
using namespace std;
constexpr int INF = 1'000'000'001;
constexpr int N = 200'000;
char s[N + 1];

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    scanf("%s", s);
    vector<int> dp(n, INF);
    int dot = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '.') {
            dot = i;
            break;
        }
        if (s[i + 1] > '4') {
            dp[i] = 1;
        } else if (s[i + 1] == '4') {
            dp[i] = dp[i + 1] + 1;
        }
    }
    int carry = 0;
    if (s[dot + 1] > '4' || s[dot + 1] == '4' && t >= dp[dot + 1] + 1) {
        s[dot] = '\0';
        carry = 1;
        for (int i = dot - 1; i >= 0; i--) {
            if (s[i] == '9') {
                s[i] = '0';
            } else {
                s[i] += 1;
                carry = 0;
                break;
            }
        }
    } else {
        for (int i = dot + 1; i < n; i++) {
            if (t >= dp[i]) {
                s[i] += 1;
                s[i + 1] = '\0';
                break;
            }
        }
    }
    if (carry) printf("%d%s\n", carry, s);
    else printf("%s\n", s);
    return 0;
}

