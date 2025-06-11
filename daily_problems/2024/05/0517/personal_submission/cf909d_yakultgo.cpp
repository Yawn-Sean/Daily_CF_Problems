#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

#define MAXN 1000011
char a[MAXN], c[MAXN];
ll sze[MAXN];
int main() {
    scanf("%s", a + 1);
    ll n = strlen(a + 1), cnt = 0, ans = 0;
    for (ll i = 1; i <= n; ++i)
        if (a[i] == c[cnt])
            ++sze[cnt];
        else
            c[++cnt] = a[i], sze[cnt] = 1;
    while (cnt > 1) {
        for (ll i = 1; i <= cnt; ++i)
            if (i == 1 || i == cnt)
                --sze[i];
            else
                sze[i] -= 2;
        ll cur = 0;
        for (ll i = 1; i <= cnt; ++i) {
            if (sze[i] <= 0) continue;
            if (c[i] == c[cur])
                sze[cur] += sze[i];
            else
                c[++cur] = c[i], sze[cur] = sze[i];
        }
        ++ans;
        cnt = cur;
    }
    cout << ans << endl;
    return 0;
}