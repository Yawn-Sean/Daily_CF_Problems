#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1000;
char s[N + 1];

int main() {
    int n;
    scanf("%d%s", &n, s);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    auto f = [&] (int x) -> int {
        char t[2] {x + '0', (x ^ 1) + '0'};
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i % 2]) res += 1;
        }
        return res;
    };
    printf("%d\n", min(f(0), f(1)));
    return 0;
}

