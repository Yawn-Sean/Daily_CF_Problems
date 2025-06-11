#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

long long det[MAXN], det2[MAXN + 10];

int main() {
    int n; scanf("%d", &n);
    long long now = 0, inc = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x); x--;
        now += abs(x - i);
        if (x > i) inc--;
        else inc++;

        int p = (n - i) % n;
        det[p] += x - abs(x - (n - 1)) - 1;
        det2[p] -= 2;

        p = (x - i + n) % n;
        det2[p] += 2;
    }

    int best = 0;
    long long val = now;
    for (int i = 1; i < n; i++) {
        now += det[i] + inc;
        inc += det2[i];
        if (now < val) best = i, val = now;
    }
    printf("%lld %d\n", val, best);
    return 0;
}
