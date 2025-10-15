#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;
char s[MAXN + 5];

int main() {
    scanf("%d%s", &n, s + 1);
    int cnt[2] = {0};
    for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) cnt[k] += (s[i] == (i & 1 ^ k) + '0' ? 0 : 1);
    printf("%d\n", min(cnt[0], cnt[1]));
    return 0;
}
