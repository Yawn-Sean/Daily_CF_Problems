#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n;
char s[MAXN + 10];
long long ans[30];

int last[MAXN + 10][26];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) last[i][j] = last[i - 1][j];
        last[i][s[i] - 'a'] = i;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> vec;
        for (int j = 0; j < 26; j++) vec.push_back(last[i][j]);
        sort(vec.begin(), vec.end(), greater<int>());
        for (int j = 0; j < 26; j++) ans[j + 1] += vec[j];
    }

    int ds = 0;
    for (int j = 0; j < 26; j++) if (last[n][j] > 0) ds++;
    printf("%d\n", ds);
    for (int i = 1; i <= ds; i++) printf("%lld\n", ans[i] - ans[i + 1]);
    return 0;
}
