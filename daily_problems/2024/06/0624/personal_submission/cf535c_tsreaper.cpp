#include <bits/stdc++.h>
using namespace std;

int A, B, q, l, t, m;

long long calc(int l, int r) {
    long long x = A + 1LL * (l - 1) * B;
    long long y = A + 1LL * (r - 1) * B;
    return (x + y) * (r - l + 1) / 2;
}

bool check(int r) {
    return calc(r, r) <= t && calc(l, r) <= 1LL * m * t;
}

int main() {
    scanf("%d%d%d", &A, &B, &q);
    while (q--) {
        scanf("%d%d%d", &l, &t, &m);
        if (calc(l, l) > t) { printf("-1\n"); continue; }
        int head = l, tail = 4e6;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (check(mid)) head = mid;
            else tail = mid - 1;
        }
        printf("%d\n", head);
    }
    return 0;
}
