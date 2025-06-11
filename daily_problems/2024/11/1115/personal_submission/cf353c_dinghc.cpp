#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N];
int pre[N + 1];
char s[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pre[i + 1] = pre[i] + a[i];
    }
    scanf("%s", s);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            curr = max(pre[i], curr + a[i]);
        }
    }
    printf("%d\n", curr);
    return 0;
}

