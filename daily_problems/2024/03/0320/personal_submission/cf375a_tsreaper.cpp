#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

char s[MAXN + 10];
int cnt[10];

int main() {
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) cnt[s[i] - '0']++;

    vector<int> vec = {1, 6, 8, 9};
    for (int x : vec) cnt[x]--;

    int t = 0;
    for (int i = 1; i <= 9; i++) for (int j = 1; j <= cnt[i]; j++) t = (t * 10 + i) % 7, printf("%d", i);
    t = t * 10000 % 7;

    int p = 1;
    for (int i = 1; i <= cnt[0]; i++) p = p * 10 % 7;

    while (true) {
        int x = 0;
        for (int y : vec) x = x * 10 + y;
        if ((t + x) * p % 7 == 0) break;
        next_permutation(vec.begin(), vec.end());
    }

    for (int x : vec) printf("%d", x);
    for (int i = 1; i <= cnt[0]; i++) printf("0");
    printf("\n");
    return 0;
}
