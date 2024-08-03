#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;

char s[MAXN + 10];
int cnt1[MAXN + 10], cnt2[MAXN + 10];

void prepare(int *cnt) {
    int n = strlen(s);
    for (int i = 0; s[i]; i++) if (s[i] == '1') cnt[n - 1 - i] = 1;
    for (int i = n + 5; i >= 0; i--) for (int j = i; cnt[j] && cnt[j + 1]; j += 2) {
        cnt[j + 2]++;
        cnt[j]--; cnt[j + 1]--;
    }
}

int main() {
    scanf("%s", s); n = strlen(s);
    prepare(cnt1);
    scanf("%s", s); n = max((int) strlen(s), n);
    prepare(cnt2);
    for (int i = n + 5; i >= 0; i--) {
        if (cnt1[i] && !cnt2[i]) { printf(">\n"); return 0; }
        if (!cnt1[i] && cnt2[i]) { printf("<\n"); return 0; }
    }
    printf("=\n");
    return 0;
}
