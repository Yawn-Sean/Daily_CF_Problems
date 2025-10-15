#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans;
char s1[MAXN + 5], s2[MAXN + 5];

int main() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    for (int i = 1, j = n; i <= j; i++, j--) {
        if (i == j) {
            if (s1[i] != s2[i]) ans++;
        } else {
            unordered_map<int, int> cnt;
            cnt[s1[i] - 'a']++; cnt[s1[j] - 'a']++;
            cnt[s2[i] - 'a']++; cnt[s2[j] - 'a']++;
            if (cnt.size() == 4) ans += 2;
            else if (cnt.size() == 3) {
                if (s1[i] == s1[j]) ans += 2;
                else ans++;
            } else if (cnt.size() == 2) {
                if (cnt[s1[i] - 'a'] != 2) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
