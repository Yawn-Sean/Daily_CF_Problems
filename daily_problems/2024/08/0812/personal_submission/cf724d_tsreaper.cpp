#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
char s[MAXN + 10];

string ans;
bool used[MAXN + 10];

bool check() {
    for (int i = 1, j = 0; i <= n; i++) {
        if (used[i]) j = i;
        if (i - j >= m) return false;
    }
    return true;
}

void solve(char c) {
    for (int i = 1, j = 0, last = 0; i <= n; i++) {
        if (s[i] == c) last = i;
        if (used[i]) j = i;
        if (i - j >= m) {
            ans.push_back(c);
            j = last;
        }
    }
}

int main() {
    scanf("%d%s", &m, s + 1); n = strlen(s + 1);

    for (int c = 0; c < 26; c++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (s[i] == c + 'a')
            used[i] = true, cnt++;
        if (!check()) {
            for (int i = 1; i <= cnt; i++) ans.push_back(c + 'a');
            continue;
        }
        for (int i = 1; i <= n; i++) if (s[i] == c + 'a') used[i] = false;
        solve(c + 'a');
        break;
    }
    printf("%s\n", ans.c_str());
    return 0;
}
