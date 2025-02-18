#include <bits/stdc++.h>

using namespace std;
char s[10], t[10];
int n;

int count(const char p1, const char p0) {
    strcpy(t, s);
    if (p0 != p1 && t[n - 1] == 'X' && t[n - 2] == 'X') return 0;
    if (p0 != t[n - 1] && t[n - 1] != 'X' && t[n - 1] != '_') return 0;
    if (p1 != t[n - 2] && t[n - 2] != 'X' && t[n - 2] != '_') return 0;
    if (p0 != t[n - 1]) {
        if (t[n - 1] == '_') {
             t[n - 1] = p0;
        } else {
            for (int i = 0; i < n; i++) if (t[i] == 'X') {
                t[i] = p0;
            }
        }
    }
    if (p1 != t[n - 2]) {
        if (t[n - 2] == '_') {
            t[n - 2] = p1;
        } else {
            for (int i = 0; i < n; i++) if (t[i] == 'X') {
                t[i] = p1;
            }
        }
    }
    if (t[0] == '0') return 0;
    int dsh = 0, crs = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '_') dsh += 1;
        else if (t[i] == 'X') crs += 1;
    }
    int res = 1;
    if (dsh) {
        if (t[0] == '_') res *= pow(10, dsh - 1) * 9;
        else res *= pow(10, dsh);
    }
    if (crs) {
        if (t[0] == 'X') res *= 9;
        else res *= 10;
    }
    return res;
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    int ans = 0;
    if (n == 1 && (s[0] == '0' || s[0] == '_' || s[0] == 'X')) {
        ans = 1;
    } else if (s[0] != '0') {
        ans += count('0', '0');
        ans += count('2', '5');
        ans += count('5', '0');
        ans += count('7', '5');
    }
    printf("%d\n", ans);
    return 0;
}

