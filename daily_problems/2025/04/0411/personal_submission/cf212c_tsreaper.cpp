#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
char s[MAXN + 5];

long long f[MAXN + 5][2];

long long gao(int x) {
    f[1][x] = 1; f[1][x ^ 1] = 0;

    for (int i = 2; i <= n; i++) {
        if (s[i] == 'A') {
            if (s[i - 1] == 'A') {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                f[i][1] = 0;
            } else {
                f[i][0] = f[i - 1][1];
                f[i][1] = f[i - 1][0];
            }
        } else {
            if (s[i - 1] == 'A') {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
            } else {
                f[i][0] = f[i - 1][1];
            }
            f[i][1] = f[i - 1][1];
        }
    }

    if (s[n] == 'A') {
        if (s[1] == 'A') {
            if (x == 0) return f[n][0] + f[n][1];
            else return 0;
        } else {
            if (x == 0) return f[n][0] + f[n][1];
            else return f[n][1];
        }
    } else {
        if (s[1] == 'A') {
            if (x == 0) return f[n][1];
            else return f[n][0];
        } else {
            return f[n][1];
        }
    }
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    printf("%lld\n", gao(0) + gao(1));
    return 0;
}
