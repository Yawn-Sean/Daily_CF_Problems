#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

char s1[MAXN + 5], s2[MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    int cnt[2] = {0};
    for (int i = 1; s1[i]; i++) cnt[0] += s1[i] - '0';
    for (int i = 1; s2[i]; i++) cnt[1] += s2[i] - '0';
    if (cnt[1] <= (cnt[0] + 1) / 2 * 2) printf("YES\n");
    else printf("NO\n");
    return 0;
}
