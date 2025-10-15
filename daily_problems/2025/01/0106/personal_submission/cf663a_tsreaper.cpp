#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, K[MAXN + 5];

int main() {
    int k = 1;
    while (true) {
        char s[10]; scanf("%s", s);
        if (s[0] == '?') K[++m] = k;
        else if (s[0] == '+') k = 1;
        else if (s[0] == '-') k = -1;
        else if (s[0] == '=') continue;
        else { n = atoi(s); break; }
    }

    int pos = 0, neg = 0;
    for (int i = 1; i <= m; i++)
        if (K[i] > 0) pos++;
        else neg++;
    long long L, R;
    auto update = [&]() {
        L = pos - 1LL * neg * n;
        R = 1LL * pos * n - neg;
    };
    update();

    if (n < L || n > R) { printf("Impossible\n"); return 0; }
    printf("Possible\n");
    long long sm = 0;
    for (int i = 1; i <= m; i++) {
        if (K[i] > 0) {
            pos--;
            if (i > 1) printf("+ ");
        } else {
            neg--;
            printf("- ");
        }
        update();
        long long v = n - (sm + R);
        if (K[i] > 0) v = max(1LL, v);
        else v = max(-1LL * n, v);
        printf("%lld ", abs(v));
        sm += v;
    }
    printf("= %d\n", n);
    return 0;
}
