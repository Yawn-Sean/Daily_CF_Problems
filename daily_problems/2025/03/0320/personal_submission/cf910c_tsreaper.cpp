#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;

int main() {
    int n; scanf("%d", &n);

    bool ban[10] = {0};
    pli val[10];
    for (int i = 0; i < 10; i++) val[i] = {0, i};
    for (int i = 1; i <= n; i++) {
        char s[10]; scanf("%s", s);
        ban[s[0] - 'a'] = true;
        for (int j = strlen(s) - 1, p = 1; j >= 0; j--, p *= 10) val[s[j] - 'a'].first += p;
    }

    sort(val, val + 10);
    for (int i = 9; i >= 0; i--) if (!ban[val[i].second]) { val[i].first = -1; break; }

    long long ans = 0;
    for (int i = 1, j = 9; i <= 9; i++) {
        while (val[j].first < 0) j--;
        ans += i * val[j].first;
        j--;
    }
    printf("%lld\n", ans);
    return 0;
}
