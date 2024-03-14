#include <bits/stdc++.h>
#define LIM ((int) 1e9)
using namespace std;

int query(int x, int y) {
    printf("? %d %d\n", x, y); fflush(stdout);
    int d; scanf("%d", &d);
    return d;
}

int main() {
    int last = 1, d = query(1, 1);
    int head = 1, tail = LIM;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        int now = query(1, mid);
        if (mid - last == d - now) {
            last = mid; d = now;
            head = mid;
        } else {
            tail = mid - 1;
        }
    }

    int xa = query(1, head) + 1, xb = LIM - query(LIM, head);
    int ya = query(xa, 1) + 1, yb = LIM - query(xa, LIM);
    printf("! %d %d %d %d\n", xa, ya, xb, yb); fflush(stdout);
    return 0;
}
