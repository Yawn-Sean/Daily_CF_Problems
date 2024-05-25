#include <iostream>
#include <cstring>

typedef long long ll;
const ll N = 5000;
char s[N + 10];

int main() {
    scanf("%s", s);
    ll n = strlen(s), ans = 0;
    for (ll i = 0; i < n; i++)
        for (ll cur = 0, right = 0, j = i; j < n; j++) {
            if (s[j] == '(')
                cur++;
            else if (s[j] == ')')
                cur--;
            else
                cur--, right++;
            if (cur < 0) {
                if (right == 0)
                    break;
                right--, cur += 2;
            }
            if (cur == 0)
                ans++;

        }
    printf("%lld", ans);
    return 0;
}
