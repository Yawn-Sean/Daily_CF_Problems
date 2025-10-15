#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1000;

int main() {
    printf("2000\n");
    for (int i = 1; i <= N; i++) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    for (int i = N; i >= 1; i--) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    return 0;
}

