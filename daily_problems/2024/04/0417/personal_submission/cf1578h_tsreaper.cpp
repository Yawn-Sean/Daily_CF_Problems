#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
using namespace std;

int n;
char s[MAXN + 10];

int now;

int gao() {
    if (s[now] == ')') return 0;

    now++;
    int x = gao();
    now++;
    if (now > n || s[now] != '-') return x;

    now += 2;
    return max(x + 1, gao());
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    now = 1; printf("%d\n", gao());
    return 0;
}
