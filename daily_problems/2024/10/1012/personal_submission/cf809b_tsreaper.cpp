#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;

bool query(int x, int y) {
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    char s[7]; scanf("%s", s);
    return s[0] == 'T';
}

int search(int head, int tail) {
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (query(mid, mid + 1)) tail = mid;
        else head = mid + 1;
    }
    return head;
}

bool validate(int pos) {
    bool ret = true;
    if (pos > 1) ret = ret && query(pos, pos - 1);
    if (pos < n) ret = ret && query(pos, pos + 1);
    return ret;
}

int main() {
    scanf("%d%*d", &n);
    int x = search(1, n);
    int y;
    if (x == 1) y = search(2, n);
    else if (x == n) y = search(1, n - 1);
    else {
        y = search(1, x - 1);
        if (!validate(y)) y = search(x + 1, n);
    }
    printf("2 %d %d\n", x, y);
    fflush(stdout);
    return 0;
}
