#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
char s[N];

int main() {
    int k;
    scanf("%d", &k);
    auto solve = [] (int n) {
        // x * (x + 1) / 2 = n
        // x = (-1+sqrt(1+8n))/2
        return static_cast<int>((sqrt(8 * n + 1) - 1) / 2);
    };
    int i = 0, cnt = 0;
    while (k) {
        int x = solve(k);
        memset(&s[cnt], 'a' + i, x + 1);
        cnt += x + 1;
        i += 1;
        k -= x * (x + 1) / 2;
    }
    s[cnt] = 'a' + i;
    s[cnt + 1] = '\0';
    printf("%s\n", s);
    return 0;
}

