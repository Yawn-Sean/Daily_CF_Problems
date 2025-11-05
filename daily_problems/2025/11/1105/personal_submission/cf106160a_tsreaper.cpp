#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef long double db;

int n;
char s[MAXN + 5];
db ans;

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    ans = s[n] - '0';
    for (int i = n - 1; i > 0; i--) ans = ans * 0.1 + (0.9 * (n - i) + 1) * (s[i] - '0');
    printf("%.12Lf\n", ans);
    return 0;
}
