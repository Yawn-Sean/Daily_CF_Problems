#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, ans;
char s[MAXN + 10];

bool check(int x) {
    return (x > 1 && s[x - 1] == s[x] - 1) || (x < n && s[x + 1] == s[x] - 1);
}

int main() {
    scanf("%d%s", &n, s + 1);
    for (int c = 25; c >= 0; c--) {
        while (true) {
            bool same = true;
            for (int i = 1; i <= n; i++) if (s[i] == c + 'a' && check(i)) {
                same = false;
                ans++;
                for (int j = i + 1; j <= n; j++) s[j - 1] = s[j];
                n--;
                break;
            }
            if (same) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
