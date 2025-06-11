#include <bits/stdc++.h>
using namespace std;

double gao(int sm, int lim) {
    if (sm * 0.5 < lim) return 2e9;

    int head = 1, tail = 1e9;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (0.5 * sm / mid >= lim) head = mid;
        else tail = mid - 1;
    }
    return 0.5 * sm / head;
}

int main() {
    int x, y; scanf("%d%d", &x, &y);
    if (x < y) printf("-1\n");
    else if (x == y) printf("%d\n", y);
    else printf("%.12f\n", min(gao(x + y, y), gao(x - y, y)));
    return 0;
}
