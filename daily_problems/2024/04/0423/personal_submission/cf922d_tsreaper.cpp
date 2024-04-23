#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
long long ans;
pii A[MAXN + 10];
char s[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int a = 0, b = 0;
        for (int j = 1; s[j]; j++) {
            if (s[j] == 's') a++;
            else ans += a, b++;
        }
        A[i] = pii(a, b);
    }

    sort(A + 1, A + n + 1, [&](pii &a, pii &b) {
        return 1LL * a.first * b.second > 1LL * b.first * a.second;
    });

    int sm = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * sm * A[i].second;
        sm += A[i].first;
    }
    printf("%lld\n", ans);
    return 0;
}
