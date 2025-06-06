#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 1'000'000;
char s[N + 1];
char ans[N + 1];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int i = 0;
    while (i < n && s[i] == '0') {
        i += 1;
    }
    int exp = 0;
    int j = 0;
    if (s[i] == '.') {
        int dot = i++;
        while (i < n && s[i] == '0') {
            i += 1;
        }
        exp = dot - i;
        ans[j++] = s[i++];
        ans[j++] = '.';
        for (int k = i; k < n; k++) {
            ans[j++] = s[k];
        }
    } else {
        int dot = n;
        int nz = i;
        ans[j++] = s[i++];
        ans[j++] = '.';
        for (int k = i; k < n; k++) {
            if (s[k] == '.') {
                dot = k;
            } else {
                ans[j++] = s[k];
            }
        }
        exp = dot - nz - 1;
    }
    while (ans[j - 1] == '.' || ans[j - 1] == '0') {
        j -= 1;
    }
    ans[j] = '\0';
    if (exp) sprintf(&ans[j], "E%d", exp);
    printf("%s\n", ans);
    return 0;
}

