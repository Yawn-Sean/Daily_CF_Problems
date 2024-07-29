#include <bits/stdc++.h>
using namespace std;

int n;

int query(int r1, int c1, int r2, int c2) {
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

array<int, 4> gao(int r1, int c1, int r2, int c2) {
    int head = r1, tail = r2;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (query(mid, c1, r2, c2)) head = mid;
        else tail = mid - 1;
    }
    int R1 = head;

    head = R1; tail = r2;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (query(R1, c1, mid, c2)) tail = mid;
        else head = mid + 1;
    }
    int R2 = head;

    head = c1; tail = c2;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (query(R1, mid, R2, c2)) head = mid;
        else tail = mid - 1;
    }
    int C1 = head;

    head = C1; tail = c2;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (query(R1, C1, R2, mid)) tail = mid;
        else head = mid + 1;
    }
    int C2 = head;

    return {R1, C1, R2, C2};
}

void print(array<int, 4> &u, array<int, 4> &v) {
    printf("!");
    for (int i = 0; i < 4; i++) printf(" %d", u[i]);
    for (int i = 0; i < 4; i++) printf(" %d", v[i]);
    printf("\n"); fflush(stdout);
}

void solve1(int lim) {
    array<int, 4> u = gao(1, 1, lim, n), v = gao(lim + 1, 1, n, n);
    print(u, v);
}

void solve2(int lim) {
    array<int, 4> u = gao(1, 1, n, lim), v = gao(1, lim + 1, n, n);
    print(u, v);
}

int main() {
    scanf("%d", &n);
    
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (query(1, 1, mid, n) > 0) tail = mid;
        else head = mid + 1;
    }
    if (query(1, 1, head, n) == 1 && query(head + 1, 1, n, n) == 1) { solve1(head); return 0; }

    head = 1; tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (query(1, 1, n, mid) > 0) tail = mid;
        else head = mid + 1;
    }
    solve2(head); return 0;
}
