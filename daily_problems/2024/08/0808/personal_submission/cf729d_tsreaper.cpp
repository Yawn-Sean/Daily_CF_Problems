#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, a, b;
char s[MAXN + 10];

int main() {
    scanf("%d%d%d%*d%s", &n, &a, &b, s + 1);

    int rem = 0;
    for (int i = 1, j = 1; i <= n + 1; i++) if (i == n + 1 || s[i] == '1') {
        rem += (i - j) / b;
        j = i + 1;
    }

    vector<int> ans;
    for (int i = 1, j = 1; rem >= a && i <= n; i++) {
        if (s[i] == '1') j = i + 1;
        else if (i - j + 1 == b) {
            ans.push_back(i);
            j = i + 1;
            rem--;
        }
    }

    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
