#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, K;
char s[MAXN + 10];

bool check(int pos, char c) {
    if (pos >= 2 && c == s[pos - 2]) return false;
    if (pos >= 1 && c == s[pos - 1]) return false;
    return true;
}

int main() {
    scanf("%d%d%s", &n, &K, s + 1);
    int pos = n;
    while (pos > 0) {
        if (s[pos] - 'a' == K - 1) pos--;
        else {
            s[pos]++;
            if (check(pos, s[pos])) break;
        }
    }
    if (pos == 0) { printf("NO\n"); return 0; }
    for (int i = pos + 1; i <= n; i++) for (int c = 0; c < K; c++)
        if (check(i, c + 'a')) { s[i] = c + 'a'; break; }
    printf("%s\n", s + 1);
    return 0;
}
