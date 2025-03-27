#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, K;
char s[MAXN + 5];

void gao2(int pos) {
    s[pos] = 0;
    s[pos - 1]++;
    for (int i = pos - 1; i >= 0; i--) {
        if (s[i] > '9') s[i] = '0', s[i - 1]++;
        else break;
    }
    if (s[0] > 0) {
        s[0] = '1';
        printf("%s\n", s);
    } else {
        printf("%s\n", s + 1);
    }
}

void gao(int pos) {
    for (int i = pos; K > 0; i--, K--) {
        if (s[i] >= '0' && s[i] <= '4') break;
        s[i] = 0;
        if (s[i - 1] == '.') {
            gao2(i - 1);
            return;
        } else {
            s[i - 1]++;
        }
    }
    printf("%s\n", s + 1);
}

int main() {
    scanf("%d%d%s", &n, &K, s + 1);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (flag && s[i] >= '5' && s[i] <= '9') { gao(i); return 0; }
        if (s[i] == '.') flag = true;
    }
    printf("%s\n", s + 1);
    return 0;
}
