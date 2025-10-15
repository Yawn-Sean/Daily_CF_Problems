#include <bits/stdc++.h>
using namespace std;

int p;

bool check(int a) {
    int b = p / a;
    if (a < b) swap(a, b);
    if ((a + b) & 1) return false;
    int n = (a + b) / 2;
    int d = a - n;
    if (d <= 0 || d > n) return false;
    int m = n / d;
    if (n / m != d) return false;
    printf("%d %d\n", n, m);
    return true;
}

void solve() {
    scanf("%d", &p);
    if (p == 0) { printf("1 1\n"); return; }
    for (int i = 1; i * i <= p; i++) if (p % i == 0) {
        if (check(i)) return;
    }
    printf("-1\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
