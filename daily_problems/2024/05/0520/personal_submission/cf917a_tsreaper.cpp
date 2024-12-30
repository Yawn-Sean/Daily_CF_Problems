#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, ans;
char s[MAXN + 10];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int now = 0, t = 0;
        for (int j = i; j <= n; j++) {
            if (s[j] == '(') now++;
            else {
                now--;
                if (s[j] == '?') t++;
            }
            while (now < 0 && t > 0) now += 2, t--;
            if (now < 0) break;
            if (now == 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
