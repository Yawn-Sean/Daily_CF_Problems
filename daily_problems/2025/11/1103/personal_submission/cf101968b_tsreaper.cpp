#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<int, int> pii;

long long fac[MAXN + 5];

void solve() {
    int n; scanf("%d", &n); n *= 2;
    vector<pii> vec;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec.push_back({x, y});
        tmp.push_back(y);
    }
    sort(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    if (vec[n / 2 - 1].first == vec[n / 2].first || tmp[n / 2 - 1] == tmp[n / 2]) { printf("0\n"); return; }
    int key = tmp[n / 2];
    int a = 0, b = 0;
    for (int i = 0; i < n / 2; i++) if (vec[i].second < key) a++;
    for (int i = n / 2; i < n; i++) if (vec[i].second < key) b++;
    printf("%lld\n", fac[a] * fac[b] % MOD);
}

int main() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
