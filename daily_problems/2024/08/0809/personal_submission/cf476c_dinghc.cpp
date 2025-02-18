#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr li M = 1'000'000'007;

int main() {
    li a, b;
    scanf("%I64d%I64d", &a, &b);
    li s1 = (a + 1) * a / 2 % M;
    li s2 = (b - 1) * b / 2 % M;
    printf("%I64d\n", (b * s1 % M * s2 % M + s2 * a % M) % M);
    return 0;
}

