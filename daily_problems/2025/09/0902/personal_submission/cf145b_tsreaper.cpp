#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    if (c == d + 1) {
        int lim = min(a, b);
        if (c > lim) { printf("-1\n"); return 0; }
        for (int i = 1; i <= a - c; i++) printf("4");
        for (int i = 1; i <= c; i++) printf("47");
        for (int i = 1; i <= b - c; i++) printf("7");
        printf("\n");
    } else if (d == c + 1) {
        int lim = min(a, b);
        if (d > lim) { printf("-1\n"); return 0; }
        printf("74");
        for (int i = 1; i <= a - d; i++) printf("4");
        for (int i = 2; i < d; i++) printf("74");
        for (int i = 1; i <= b - d; i++) printf("7");
        printf("74\n");
    } else if (c == d) {
        if (a > c && b >= c) {
            for (int i = 1; i <= a - c; i++) printf("4");
            for (int i = 1; i < c; i++) printf("74");
            for (int i = 1; i <= b - c; i++) printf("7");
            printf("74\n");
        } else if (b > c && a >= c) {
            printf("7");
            for (int i = 1; i <= a - c; i++) printf("4");
            for (int i = 1; i <= c; i++) printf("47");
            for (int i = 1; i <= b - c - 1; i++) printf("7");
            printf("\n");
        } else {
            printf("-1\n");
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
