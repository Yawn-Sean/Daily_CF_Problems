#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    li n;
    scanf("%lld", &n);
    n++;
    li tot = 0LL;
    li curr = 0, nxt = 10;
    int k = 1;
    while (tot + (nxt - curr) * k < n) {
        tot += (nxt - curr) * k;
        k++;
        curr = nxt;
        nxt *= 10;
    }
    li q = (n - tot + k - 1) / k + curr - 1;
    int m = (k - (n - tot) % k) % k;
    for (int i = 0; i < m; i++) {
        q /= 10;
    }
    printf("%d\n", q % 10);
    return 0;
}

