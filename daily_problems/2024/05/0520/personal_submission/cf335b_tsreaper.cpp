#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
#define MAGIC 2600
using namespace std;

int n;
char s[MAXN + 10];

int f[MAGIC + 10][MAGIC + 10], g[MAGIC + 10][MAGIC + 10];

void update(int i, int j, int val, int t) {
    if (f[i][j] < val) f[i][j] = val, g[i][j] = t;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);

    int cnt[26] = {0};
    for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) if (cnt[i] >= 100) {
        for (int j = 1; j <= 100; j++) printf("%c", i + 'a');
        printf("\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int len = 2; len <= n; len++) for (int i = 1, j = len; j <= n; i++, j++) {
        f[i][j] = -1e9;
        update(i, j, f[i + 1][j], 1);
        update(i, j, f[i][j - 1], 2);
        if (s[i] == s[j]) update(i, j, f[i + 1][j - 1] + 2, 3);
    }
    string s1, s2;
    int i = 1, j = n;
    while (true) {
        if (g[i][j] == 1) i++;
        else if (g[i][j] == 2) j--;
        else if (g[i][j] == 3) {
            s1.push_back(s[i]); s2.push_back(s[j]);
            i++; j--;
        } else {
            if (i == j) s1.push_back(s[i]);
            break;
        }
    }
    if (s1.size() + s2.size() > 100) {
        if (s1.size() != s2.size()) s1.pop_back();
        while (s1.size() + s2.size() > 100) s1.pop_back(), s2.pop_back();
    }
    reverse(s2.begin(), s2.end());
    printf("%s%s\n", s1.c_str(), s2.c_str());
    return 0;
}
