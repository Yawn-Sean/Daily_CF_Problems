#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans;
char s[MAXN + 5];

int A[MAXN + 5], f[MAXN + 5];

void gao(string ord) {
    for (int i = 0, idx = 1; i < 4; i++) for (int j = 1; j <= n; j++)
        if (s[j] == ord[i]) A[j] = idx++;

    for (int i = 1; i <= n; i++) f[i] = n + 1;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        int head = 0, tail = i - 1;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (f[mid] <= A[i]) head = mid;
            else tail = mid - 1;
        }
        tmp = max(tmp, head + 1);
        f[head + 1] = A[i];
    }
    ans = min(ans, n - tmp);
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);

    ans = n;
    string ord = "hdcs";
    for (int i = 0; i < 24; i++) {
        gao(ord);
        next_permutation(ord.begin(), ord.end());
    }
    printf("%d\n", ans);
    return 0;
}
