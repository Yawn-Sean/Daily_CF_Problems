#include <bits/stdc++.h>

using namespace std;
const int N = 1'000'000'000;

int main() {
    int a, b, mod;
    scanf("%d%d%d", &a, &b, &mod);
    a = min(a, mod);
    for (int i = 0; i <= a; i++) {
        if ((mod - 1LL * i * N % mod) % mod > b) {
            printf("1 %09d\n", i);
            return 0;
        }
    }
    printf("2\n");
    return 0;
}

