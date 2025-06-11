#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    int a = y, b = y;
    int ans = 2;
    while (a < x) {
        int na = a + b - 1;
        b = a;
        a = na;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

