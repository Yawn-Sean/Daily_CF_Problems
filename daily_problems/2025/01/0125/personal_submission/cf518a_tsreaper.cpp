#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
char s1[MAXN + 5], s2[MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1); n = strlen(s1 + 1);
    s1[n]++;
    for (int i = n; i > 0; i--) {
        if (s1[i] > 'z') {
            s1[i] = 'a';
            s1[i - 1]++;
        } else {
            break;
        }
    }
    if (strcmp(s1 + 1, s2 + 1) < 0) printf("%s\n", s1 + 1);
    else printf("No such string\n");
    return 0;
}
