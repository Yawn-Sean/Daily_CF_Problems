#include <bits/stdc++.h>
#define MAXN 8
using namespace std;

int n, ans;
char s[MAXN + 5], t[MAXN + 5];

int gao(char *s) {
    if (s[1] == '0') return 0;

    int k;
    if (n > 2 && s[1] == '_') k = 9;
    else k = 1;
    for (int i = 2; i <= n - 2; i++) if (s[i] == '_') k *= 10;

    auto chr = [&](int pos, char c) {
        return s[pos] == '_' || s[pos] == c;
    };

    int ret = 0;
    if (n > 2 && chr(n - 1, '0') && chr(n, '0')) ret += k;
    if (chr(n - 1, '2') && chr(n, '5')) ret += k;
    if (chr(n - 1, '5') && chr(n, '0')) ret += k;
    if (chr(n - 1, '7') && chr(n, '5')) ret += k;
    return ret;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    if (n == 1) {
        if (s[1] == '0' || s[1] == 'X' || s[1] == '_') printf("1\n");
        else printf("0\n");
        return 0;
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) if (s[i] == 'X') { flag = true; break; }

    if (flag) for (int x = 0; x <= 9; x++) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'X') t[i] = x + '0';
            else t[i] = s[i];
        }
        ans += gao(t);
    } else {
        ans += gao(s);
    }
    printf("%d\n", ans);
    return 0;
}
