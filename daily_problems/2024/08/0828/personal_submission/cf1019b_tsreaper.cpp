#include <bits/stdc++.h>
using namespace std;

int n;

int sgn(int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int query(int x) {
    printf("? %d\n", x); fflush(stdout);
    int a; scanf("%d", &a);
    printf("? %d\n", x + n / 2); fflush(stdout);
    int b; scanf("%d", &b);
    return sgn(a - b);
}

void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
    exit(0);
}

int main() {
    scanf("%d", &n);
    if (n / 2 % 2) answer(-1);

    int t = query(1);
    if (t == 0) answer(1);

    int head = 1, tail = n / 2;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        int x = query(mid);
        if (x == t) head = mid + 1;
        else tail = mid;
    }
    answer(head);
    return 0;
}
