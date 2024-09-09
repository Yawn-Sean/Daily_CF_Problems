#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define SIGMA 26
using namespace std;

char s1[MAXN + 10], s2[MAXN + 10], s3[MAXN + 10];

int cnt1[SIGMA], cnt2[SIGMA], cnt3[SIGMA];

void prepare(char *s, int *cnt) {
    for (int i = 1; s[i]; i++) cnt[s[i] - 'a']++;
}

int main() {
    scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
    prepare(s1, cnt1); prepare(s2, cnt2); prepare(s3, cnt3);
    int a1 = 0, a2 = 0;
    for (int i = 0; ; i++) {
        auto gao = [&]() {
            int mn = 1e9;
            for (int j = 0; j < 26; j++) {
                int rem = cnt1[j] - cnt2[j] * i;
                if (rem < 0) return false;
                if (cnt3[j] > 0) mn = min(mn, rem / cnt3[j]);
            }
            if (i + mn > a1 + a2) a1 = i, a2 = mn;
            return true;
        };
        if (!gao()) break;
    }
    for (int i = 1; i <= a1; i++) printf("%s", s2 + 1);
    for (int i = 1; i <= a2; i++) printf("%s", s3 + 1);
    for (int i = 0; i < 26; i++) for (int j = 1; j <= cnt1[i] - cnt2[i] * a1 - cnt3[i] * a2; j++) printf("%c", i + 'a');
    printf("\n");
    return 0;
}
