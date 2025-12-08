#include <bits/stdc++.h>
using namespace std;
 
bool solve() {
    long long a, b; scanf("%lld%lld", &a, &b);
    if (a > b) swap(a, b);
    if (a == 1 || b == 1) return false;
    if (a == b) return a % 2 == 0;
    if (a % (b - a)) return false;
    for (int t = 2; t <= 4; t++) {
        long long w = b / t;
        if (w > 0 && w < a && b % w == 0 && b % (a - w) == 0) return true;
    }
    return false;
}
 
int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--)
        if (solve()) printf("SI\n");
        else printf("NO\n");
    return 0;
}
